#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct edge{
    int to;
    int cap;
    int rev;
};
struct Ford{
    vector<vector<edge>> G;
    int V;
    vector<int> used;
    Ford(int N){
        V = N;
        used.resize(V, 0);
        G.resize(V);
    }
    void add(int u, int v, int c){
        edge e1 = {v, c, (int)G[v].size()};
        G[u].push_back(e1);
        edge e2 = {u, 0, (int)G[u].size() - 1};
        G[v].push_back(e2);
    }
    int dfs(int s, int t, int f){
        if(s == t) return f;
        used[s] = 1;
        for(edge &e: G[s]){
            if(used[e.to] == 0 && e.cap > 0){
                long long temp = dfs(e.to, t, min(f, e.cap));
                if(temp > 0){
                    e.cap -= temp;
                    G[e.to][e.rev].cap += temp;
                    return temp;
                }
            }
        }
        return 0;
    }
    int solve(int s, int t){
        int ans = 0;
        int INF = 1e9;
        while(1){
            used.assign(V, 0);
            int res = dfs(s, t, INF);
            if(res == 0) return ans;
            ans += res;
        }
    }
};
int main(){
    int N;
    cin >> N;
    Ford Ford(2 * N + 2);
    int can[N][N];//can[i][j] = 1でペアが作れる
    vector<int> a(N), b(N), c(N), d(N);
    for(int i = 0; i < N; i++) cin >> a[i] >> b[i];
    for(int i = 0; i < N; i++) cin >> c[i] >> d[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(a[i] < c[j] && b[i] < d[j]) can[i][j] = 1;
            else can[i][j] = 0;
        }
    }
    for(int i = 0; i < N; i++){
        Ford.add(2 * N, i, 1);
        Ford.add(N + i, 2 * N + 1, 1);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(can[i][j]) Ford.add(i, N + j, 1);
        }
    }
    int ans = Ford.solve(2 * N, 2 * N + 1);
    cout << ans << endl;
}