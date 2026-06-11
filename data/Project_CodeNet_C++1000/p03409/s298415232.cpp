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
    ll n;
    cin >> n;
    Vi a(n),b(n),c(n),d(n);
    rp(i,n) cin >> a[i] >> b[i];
    rp(i,n) cin >> c[i] >> d[i];
    ll ctr=0;
    vi usedr(n,0),usedb(n,0);
    
    rp(i,n){
        ll which;
        ll minx=1000;
        rp(j,n){
            if(usedb[j]==0&&chmin(minx,c[j])){
                which=j;
            }
        }
        usedb[which]=1;
        ll pos=-1;
        ll maxy=-1;
        rp(j,n){
            if(usedr[j]==1) continue;
            if(a[j]<c[which]&&b[j]<d[which]){
                if(chmax(maxy,b[j])){
                    pos=j;
                }
            }
        }
        if(pos>=0){
            usedr[pos]=1;
            ctr++;
        }
    }
    print(ctr);
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}