#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int v, e;
const int MAX_N = 100100;
// 隣接リスト
vector<int> graph[MAX_N];
bool used[MAX_N];
// トポロジカルソートされた数列
vector<int> ans;

void dfs(int u) {
  if(used[u]) return;
  used[u] = true;
  for(auto& i: graph[u]) dfs(i);
  // 帰りがけ順で追加
  ans.push_back(u);
}

void tsort() {
  for(int i=0; i<v; ++i) dfs(i);
  reverse(ans.begin(), ans.end());
}

int main() {
    int N, M; cin >> N >> M;
    v = N;
    e = N + M - 1;

    vector<int> incount(N, 0);
    for (int i = 0; i < N+M-1; i++) {
        int s, t; cin >> s >> t;
        s--; t--;
        graph[s].push_back(t);
        incount[t]++;
    }

    tsort();
    
    vector<int> oya(N);
    oya[ans[0]] = 0;
    for (int i = 0; i < N; i++) {
        int t = ans[i];
        for (auto x : graph[t]) {
            if (incount[x] == 1) {
                oya[x] = t+1;
            } else {
                incount[x]--;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << oya[i] << endl;
    }
    return 0;
}