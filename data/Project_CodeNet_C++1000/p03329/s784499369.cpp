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

int memo[100050];

int bank(int c){
    if(c<6) return c;
    if(memo[c]!=0) return memo[c];
    int ans=1<<30;
    chmin(ans,1+bank(c-6));
    if(c>=36)chmin(ans,1+bank(c-36));
    if(c>=216)chmin(ans,1+bank(c-216));
    if(c>=1296)chmin(ans,1+bank(c-1296));
    if(c>=7776)chmin(ans,1+bank(c-7776));
    if(c>=46656)chmin(ans,1+bank(c-46656));
    if(c>=9)chmin(ans,1+bank(c-9));
    if(c>=81)chmin(ans,1+bank(c-81));
    if(c>=729)chmin(ans,1+bank(c-729));
    if(c>=6561)chmin(ans,1+bank(c-6561));
    if(c>=59049)chmin(ans,1+bank(c-59049));
    memo[c]=ans;
    return ans;
}
void solve(){
    int n;
    cin >> n;
    print(bank(n));
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}