#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,M;
  cin >> N >> M;
  vector<int> child[N];
  bool seen[N];
  vector<int> Deep(N);
  vector<int> CandParent[N];
  vector<int> num(N);
  
  for (int i = 0; i < N; i++) {
    seen[i] = false;
  }
  for (int i = 0; i < N-1+M; i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    child[a].push_back(b);
    CandParent[b].push_back(a);
    num[b]++;
    seen[b] = true;
  }
  int Parent = 0;
  for (int i = 0; i < N; i++) {
    if (!seen[i]) {
      Parent = i;
    }
  }

  for (int i = 0; i < N; i++) {
    Deep[i] = 999999;
  }
  Deep[Parent] = 0;
  int cnt = 0;
  vector<int> vec = {Parent};
  while (!vec.empty()) {
    vector<int> newvec = {};
    for (int j = 0; j < (int)vec.size(); j++) {
      for (int k = 0; k < (int)child[vec[j]].size(); k++) {
        int C = child[vec[j]][k];
        num[C]--;
        if (num[C] == 0) {
          newvec.push_back(C);
          Deep[C] = cnt+1;
        }
      }
    }
    cnt++;
    vec = newvec;
  }
  
  vector<int> ans(N);
  ans[Parent] = -1;
  for (int i = 0; i < N; i++) {
    if (i == Parent) {
      continue;
    }
    for (int j = 0; j < (int)CandParent[i].size(); j++) {
      if (Deep[i] - 1 == Deep[CandParent[i][j]]) {
        ans[i] = CandParent[i][j];
      }
    }
  }

  for (int i = 0; i < N; i++) {
    cout << ans[i] + 1 << endl;
  }
  return 0;
}