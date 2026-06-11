#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    vector<int> indeg(n);
    REP(i,n + m - 1){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].emplace_back(b);
        indeg[b]++;
    }
    int s;
    REP(i,n){
        if(indeg[i] == 0){
            s = i;
            break;
        }
    }
    vector<int> ans(n);
    queue<int> que;
    que.emplace(s);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(auto v : G[now]){
            indeg[v]--;
            if(indeg[v] == 0){
                que.emplace(v);
                ans[v] = now + 1;
            }
        }
    }
    REP(i,n){
        cout << ans[i] << endl;
    }
    return 0;
}