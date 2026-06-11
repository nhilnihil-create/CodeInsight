#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int N,M;
bool Graph[55][55];
int a[55];
int b[55];

bool DFS() {
  bool can[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      can[i][j] = false;
    }
  }
  for (int i = 0; i < N; i++) {
    stack<int> st;
    st.push(i);
    while (!st.empty()) {
      int a = st.top();
      st.pop();
      can[i][a] = true;
      for (int j = 0; j < N; j++) {
        if (Graph[a][j]) {
          if (!can[i][j]) {
            can[i][j] = true;
            st.push(j);
          } 
        }
      }
    }
  }
  bool res = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (res && can[i][j]) {
        res = true;
      } else {
        res = false;
      }
    }
  }
  return res;
}

int main() {
  int ans = 0;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    Graph[a[i]][b[i]] = true;
    Graph[b[i]][a[i]] = true;
  }

  for (int i = 0; i < M; i++) {
    Graph[a[i]][b[i]] = false;
    Graph[b[i]][a[i]] = false;
    if (!DFS()) {
      ans++;
    }
    Graph[a[i]][b[i]] = true;
    Graph[b[i]][a[i]] = true;
  }
  cout << ans << endl;
  return 0;
}