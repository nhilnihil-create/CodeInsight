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
    int n,m;
    cin >> n >> m;
    vi p(n+1);
    vi gru(n+1,0);
    repi(i,1,n+1){
        cin >> p.at(i);
    }
    vector<vector<int>> gra(n+1,vi(0));
    rp(i,m){
        int x,y;
        cin >> x >> y;
        gra[x].pb(y);
        gra[y].pb(x);
    }
    int gnum=1;
    repi(i,1,n+1){
        if(gru[i]!=0) continue;
        gru[i]=gnum;
        queue<int> que;
        for(int nxt:gra[i]){
            if(gru[nxt]!=0) continue;
            gru[nxt]=gnum;
            que.push(nxt);
        }
        while(!que.empty()){
            int q=que.front(); que.pop();
            for(int nxt:gra[q]){
                if(gru[nxt]!=0) continue;
                gru[nxt]=gnum;
                que.push(nxt);
            }
        }
        gnum++;
    }
    vector<vi> scr(n+1,vi(0)),name(n+1,vi(0));
    int ans=0;
    repi(i,1,n+1){
        if(gru[i]==0){
            if(p[i]==i) ans++;
            continue;
        }
        scr[gru[i]].pb(p[i]);
        name[gru[i]].pb(i);
    }
    repi(i,1,n+1){
        for(auto num:scr[i]){
            int a=upper_bound(all(name[i]),num)-lower_bound(all(name[i]),num);
            if(a>0) ans++;
        }
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