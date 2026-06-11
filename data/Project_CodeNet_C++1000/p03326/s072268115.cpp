#include <bits/stdc++.h>
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
#define rp(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

void solve(){
    ll n,m;
    cin >> n >> m;
    Vi x(n),y(n),z(n);
    matrix option(8,Vi(n,0));
    rp(i,n) {
        cin >> x.at(i) >> y.at(i) >> z.at(i);
        rp(j,8){
            if(j&1) option[j][i]+=x[i];
            else option[j][i]-=x[i];
            if(j&2) option[j][i]+=y[i];
            else option[j][i]-=y[i];
            if(j&4) option[j][i]+=z[i];
            else option[j][i]-=z[i];
        }
    }
    rp(j,8){
        Sort(option[j]);
    }
    ll ans=0;
    rp(j,8){
        ll sum=0;
        rp(i,m){
            sum+=option[j][i];
        }
        chmax(ans,sum);
    }
    print(ans);
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}