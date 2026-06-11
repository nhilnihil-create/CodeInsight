#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

struct TopologicalSort {
    int n;
    vector <set<int>> G;
    vector<bool> used;
    vector<int> indeg, p;

    TopologicalSort() {}
    TopologicalSort(int sz) : n(sz), G(n), used(n), indeg(n), p(0) {}

    void add_edge(int s, int t) {
        G[s].insert(t);
    }

    void bfs(int s) {
        queue<int> q;
        q.push(s);
        used[s] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            p.push_back(v);
            for (int u:G[v]) {
                indeg[u]--;
                if (indeg[u] == 0 && !used[u]) {
                    used[u] = 1;
                    q.push(u);
                }
            }
        }
    }

    vector<int> build() {
        fill(used.begin(), used.end(), 0);
        fill(indeg.begin(), indeg.end(), 0);

        for (int i = 0; i < n; i++) {
            for (int v:G[i]) {
                indeg[v]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0 && !used[i]) {
                bfs(i);
            }
        }

        return p;
    }
};

///////////////////////////////////////////////////////////////////////////////
vector<int> G[100005];

int main(){
  int N, M;
  cin >> N >> M;
  int a[N - 1 + M], b[N - 1 + M];
  for(int i = 0; i < N - 1 + M; i++){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    G[a[i]].push_back(b[i]);
  }

  TopologicalSort ts(N);
  for(int i = 0; i < N - 1 + M; i++){
    ts.add_edge(a[i], b[i]);
  }

  vector<int> tsg = ts.build();

  int ans[N];
  fill(ans, ans + N, 0);
  for(int node : tsg){
    for(int nxt : G[node]){
      ans[nxt] = node + 1;
    }
  }

  for(int i = 0; i < N; i++){
    cout << ans[i] << endl;
  }
  cout << endl;
  return 0;
}