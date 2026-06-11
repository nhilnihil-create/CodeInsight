#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)
#define mp make_pair

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 n;
    cin >> n;
    vector<vector<int32>> adj(n);
    REP(i,n-1){
        int32 a,b;
        cin >> a >> b;
        a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int32> c(n);
    REP(i,n)cin >> c[i];
    sort(ALL(c),greater<int32>());
    vector<int32> res(n,-1);
    int64 sum = 0;
    res[0] = c[0];
    queue<int32> que;
    que.push(0);
    int32 idx = 1;
    while(!que.empty()){
        int32 x = que.front();
        que.pop();
        for(int32 y : adj[x]){
            if(res[y] > 0)continue;
            res[y] = c[idx];
            idx++;
            que.push(y);
            sum += res[y];
        }
    }
    cout << sum << endl;
    REP(i,n){
        if(i != 0)cout << " ";
        cout << res[i];
    }
    cout << endl;
    return 0;
}