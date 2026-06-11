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
    ll h,w;
    cin >> h >> w;
    vector<string> s(h);
    rp(i,h) cin >> s[i];
    rp(i,h){
        rp(j,w){
            if(s[i][j]=='.'){
                int ctr=0;
                if(i-1>=0){
                    if(j-1>=0&&s[i-1][j-1]=='#') ctr++;
                    if(s[i-1][j]=='#') ctr++;
                    if(j+1<w&&s[i-1][j+1]=='#') ctr++;
                }
                if(i+1<h){
                    if(j-1>=0&&s[i+1][j-1]=='#') ctr++;
                    if(s[i+1][j]=='#') ctr++;
                    if(j+1<w&&s[i+1][j+1]=='#') ctr++;
                }
                if(j-1>=0&&s[i][j-1]=='#') ctr++;
                if(j+1<w&&s[i][j+1]=='#') ctr++;
                s[i][j]=(char)('0'+ctr);
            }
            
        }
    }
    rp(i,h){
        print(s[i]);
    }
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}