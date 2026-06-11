// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl;
#define fs first
#define sc second
#define pb push_back
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef priority_queue<ll> PQI;
typedef priority_queue<P> PQP;
typedef vector<vector<P>> pvec;
typedef vector<vector<ll>> vvec;
typedef vector<ll> vec;
const vector<int> dx = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
const int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30);
const int INF = (1LL << 60);
const double EPS = (1 >> 30);
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}

vec dist;
int id=0,mx=0;
void dfs(int now,int pre,vvec &G){
    if(pre!=-1) dist[now]=dist[pre]+1;
    if(chmax(mx,dist[now])) id=now;
    for(auto &next:G[now]){
        if(pre==next) continue;
        dfs(next,now,G);
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //---------------------------------------------
    
    int n;
    cin>>n;
    vvec G(n);
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    dist.resize(n,0);
    mx=0;
    id=0;
    dfs(0,-1,G);
    mx=0;
    dist.assign(n,0);
    dfs(id,-1,G);

    if(mx%3!=1) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}