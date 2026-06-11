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
ll n,m;
matrix gra(52);
vector<PLL> vp;
Vi seen(52,0);
ll dfs(ll s,ll st,ll en){
    for(auto nxt:gra[s]){
        if(s==st&&nxt==en) continue;
        if(s==en&&nxt==st) continue;
        if(seen[nxt]==0){
            seen[nxt]=1;
            dfs(nxt,st,en);
        }
    }
    ll ctr=0;
    for(auto l:seen){
        if(l==1) ctr++;
    }
    return ctr;
}
void solve(){
    cin >> n >> m;
    rp(i,m){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        gra[a].pb(b);
        gra[b].pb(a);
        vp.pb(mp(a,b));
    }
    ll ans=0;
    rp(i,m){
        ll st=vp[i].first, en=vp[i].second;
        ll num=dfs(0,st,en);
        if(n!=num) {
            ans++;
            //print(i);
        }
        fill(all(seen),0);
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