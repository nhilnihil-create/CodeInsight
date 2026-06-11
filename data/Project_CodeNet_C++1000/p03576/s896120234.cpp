#include "bits/stdc++.h"
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

ll n,k;
Vi x,y;
vector<PLL> v;


int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    cin>>n>>k;
    x.resize(n); y.resize(n);
    v.resize(n);
    rep(i,n){
        cin>>x[i]>>y[i];
        v[i] = mp(x[i],y[i]);
    }
    ll ans = INT64_MAX;
    ll tmp = 0;
    ll mx;ll my;ll ix;ll iy;
    rep(i,n){
        repi(j,i+1,n){
            rep(ii,n){
                repi(jj,ii+1,n){
                    ll mx = max(x[i],x[j]);
                    ll ix = min(x[i],x[j]);
                    ll my = max(y[ii],y[jj]);
                    ll iy = min(y[ii],y[jj]);
                    tmp  = 0;
                    rep(kk,n){
                        ll _x = v[kk].first;
                        ll _y = v[kk].second;
                        if(_x >= ix && _x <= mx){
                            if(_y >= iy && _y <= my){
                                tmp++;
                            }
                        }
                    }
                    if(tmp>=k){
                        chmin(ans,(mx-ix)*(my-iy));
                    }
                }
            }
        }
    }
    print(ans);
    return 0;
}