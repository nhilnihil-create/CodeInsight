#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> v;
vector<bool> visited(51);
vector<unordered_set<int>> vg(51);

void DFS(int k){
  visited[k] = true;
  for(auto x: vg[k]){
    if(visited[x]){
      continue;
    }
    DFS(x);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v.emplace_back(a, b);
    vg[a].insert(b);
    vg[b].insert(a);
  }
  long long ans = 0;

  for(int i = 0; i < M; i++){
    fill(visited.begin(), visited.end(), false);
    int a = v[i].first;
    int b = v[i].second;
    vg[a].erase(b);
    vg[b].erase(a);
    visited[0] = true;
    DFS(0);
    vg[a].insert(b);
    vg[b].insert(a);
    for(int j = 0; j < N; j++){
      if(!visited[j]){
        break;
      }
      if(j == N-1){
        ans++;
      }
    }
  }
  cout << M - ans <<endl;
}
