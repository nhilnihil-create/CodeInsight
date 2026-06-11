#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

#define MAX_N 10000

int n;
vector<int> G[MAX_N];
vector<int> c;
bool visited[MAX_N];
int ans[MAX_N];
int cnt = 0;

void dfs(int now){
    ans[now] = c[cnt++];
    visited[now] = true;
    for(auto v : G[now]){
        if(!visited[v]) dfs(v);
    }
}

signed main(){
    cin >> n;
    REP(i,n - 1){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    REP(i,n){
        int t;
        cin >> t;
        c.emplace_back(t);
    }
    sort(ALL(c));
    reverse(ALL(c));
    dfs(0);
    int m = 0;
    for(int i = 1; i < n; i++){
        m += c[i];
    }
    cout << m << endl;
    REP(i,n){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}