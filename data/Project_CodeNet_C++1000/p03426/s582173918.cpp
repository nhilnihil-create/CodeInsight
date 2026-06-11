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
    ll h,w,d;
    cin >> h >> w >> d;
    map<int,P> ma;
    rp(i,h){
        rp(j,w){
            int a;
            cin >> a;
            ma[a]=mp(i,j);
        }
    }
    matrix tab(d,Vi(1,0));
    repi(i,d+1,h*w+1){
        P p1=ma[i],p2=ma[i-d];
        ll ind=(i-1)/d-1;
        tab[i%d].pb(tab[i%d][ind]+abs(p1.first-p2.first)+abs(p1.second-p2.second));
    }
    ll q;
    cin >> q;
    Vi ans;
    while(q--){
        ll l,r;
        cin >> l >> r;
        ll res=l%d;
        ans.pb(tab[res][(r-1)/d]-tab[res][(l-1)/d]);
    }
    for(auto an:ans){
        print(an);
    }
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}