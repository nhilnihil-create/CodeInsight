#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define ANS(n) cout << (n) << endl
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)
#define mp make_pair

int32 n,m;
vector<int32> g[(int32)1e5];

int32 color[(int32)1e5];

bool bipartite(int32 v, int32 c){
    color[v] = c;
    REP(i,g[v].size()){
        if(color[g[v][i]] == c)return false;
        if(color[g[v][i]] == 0 && !bipartite(g[v][i], -c))return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    REP(i,m){
        int32 a,b;
        cin >> a >> b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    if(bipartite(0, 1)){
        int32 cnt = 0;
        REP(i,n)
            if(color[i] == 1)cnt++;
        ANS(cnt * (n - cnt) - m);
    }else{
        ANS(n * (n-1) / 2 - m);
    }
    return 0;
}