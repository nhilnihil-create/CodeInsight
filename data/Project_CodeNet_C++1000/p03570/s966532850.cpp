#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> Pair;
 
const int INF = 0x3fffffff;
int N;
char S[200001];
int type[200001];
int dp[200001];
int nxt[200001];
queue<int> qs[200001];
vector<int> es[200001];
map<int, vector<int>> belong;
 
int main() {
  scanf("%s", S);
  N = strlen(S);
  
  type[0] = 0;
  belong[0].emplace_back(0);
  int bit = 0;
  for (int i=0; i<N; i++) {
    es[i].reserve(26);
    bit ^= (1 << int(S[i]-'a'));
    belong[bit].emplace_back(i+1);
    type[i+1] = bit;
  }
 
  for (auto &itr : belong) {
    auto &v = itr.second;
    if (v.empty()) continue;
    for (int i=0; i<v.size()-1; i++) {
      nxt[v[i]] = v[i+1];
    }

    for (int j=0; j<26; j++) {
      int t = itr.first ^ (1<<j);
      auto &vec = belong[t];
      auto itr = upper_bound(vec.begin(), vec.end(), v.front());
      if (itr == vec.end()) continue;
      for (int g : v) {
        while (itr != vec.end() && *itr < g) itr++;
        if (itr == vec.end()) break;
        es[g].emplace_back(*itr);
      }
    }
  }
 
  fill(dp, dp+N+1, INF);
  dp[0] = 0;
  qs[0].push(0);
  for (int i=0; i<N; i++) {
    while (!qs[i].empty()) {
      int v = qs[i].front(); qs[i].pop();
      if (v == N) continue;
      //assert(dp[v] == i);
 
      if (nxt[v] != -1) {
        int u = nxt[v];
        if (dp[u] > dp[v]) {
          dp[u] = dp[v];
          qs[i].push(u);
        }
      }
 
      for (int u : es[v]) {
        if (dp[u] > dp[v]+1) {
          dp[u] = dp[v]+1;
          qs[i+1].push(u);
        }
      }
    }
  }
 
  if (!dp[N]) dp[N]++;
  printf("%d\n", dp[N]);
}
