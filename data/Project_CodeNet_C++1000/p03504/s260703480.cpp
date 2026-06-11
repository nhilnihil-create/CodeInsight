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

ll n,c;
Vi ss,tt,cc;
vector<tuple<ll,ll,ll>> v;
ll ck[100010];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    cin>>n>>c;
    ss.resize(n);tt.resize(n); cc.resize(n);
    rep(i,n){
        cin>>ss[i]>>tt[i]>>cc[i];
        ss[i]--;
        v.pb(make_tuple(cc[i],ss[i],tt[i]));
    }
    rep(i,100010)ck[i]=0;
    sort(all(v));
    rep(i,v.size()-1){
        if(get<0>(v[i])==get<0>(v[i+1])){
            if(get<2>(v[i]) >= get<1>(v[i+1])){
                v[i+1] = make_tuple(get<0>(v[i]),get<1>(v[i]),get<2>(v[i+1]));
                v[i]=make_tuple(-1,get<1>(v[i]),get<2>(v[i+1]));
            }
        }
    }
    rep(i,v.size()){
        if(get<0>(v[i])==-1)continue;
        ck[get<1>(v[i])]++;
        ck[get<2>(v[i])]--;
    }
    ll ans = 0;
    rep(i,100009){
        ck[i+1] += ck[i];
        chmax(ans,ck[i+1]);
    }
    print(ans);
    return 0;
}