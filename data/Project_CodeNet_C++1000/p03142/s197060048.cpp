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
    int32 n, m;
    cin >> n >> m;
    vector<vector<int32>> ancestors(n);
    vector<vector<int32>> adj(n);
    vector<int32> ancestorCnt(n);
    REP(i,n-1+m){
        int32 a,b;
        cin >> a >> b;
        a--;b--;
        ancestors[b].pb(a);
        ancestorCnt[b]++;
        adj[a].pb(b);
    }
    stack<int32> st;
    REP(i,n){
        if(ancestorCnt[i] == 0)st.push(i);
    }
    vector<int32> topological(n+1, -1);
    int32 cur = 0;
    while(!st.empty()){
        int32 x = st.top();
        st.pop();
        topological[x] = cur;
        cur++;
        for(int32 y : adj[x]){
            ancestorCnt[y]--;
            if(ancestorCnt[y] == 0)st.push(y);
        }
    }
    REP(i,n){
        int32 par = n;
        for(int32 x : ancestors[i]){
            if(topological[par] < topological[x]){
                par = x;
            }
        }
        if(par == n){
            par = 0;
        }else{
            par++;
        }
        ANS(par);
    }
    return 0;
}