#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (ll i = m; i < n; ++i)
#define FORR(i, m, n) for (ll i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
const int nmax=100005;
vector<vector<int>> e(nmax);
ll dp[nmax][2];
bool mem[nmax][2];
ll dfs(int cur,bool blk,int pre=-1){
    if(mem[cur][blk]){
        return dp[cur][blk];
    }
    ll res=1;
    for(int to:e[cur]){
        if(to==pre){
            continue;
        }
        if(blk){
            (res*=dfs(to,0,cur))%=mod;
        }
        else{
            (res*=(dfs(to,0,cur)+dfs(to,1,cur))%mod)%=mod;
        }
    }
    mem[cur][blk]=true;
    return dp[cur][blk]=res;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin >> n;
    REP(i,n-1){
        int x,y;cin >> x >> y;
        x--,y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    cout << (dfs(0,0)+dfs(0,1))%mod << endl;
}