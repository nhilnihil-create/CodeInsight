#include<bits/stdc++.h>
#include<queue>
using namespace std;
vector<queue<int>>gra;
vector<int>cl;
vector<int>si;
bool dfs(int x, int c) {
  if (cl[x] != -1) {
    return cl[x] == c;
  }
  cl[x] = c;
  for (int i = 0; i < si[x]; i ++) {
    int u = gra[x].front();
    gra[x].pop();
    gra[x].push(u);
    int d = (c + 1) % 2;
    bool kj = dfs(u, d);
    if (!kj) return false;
  }
  return true;
}
int main () {
  int N, M;
  cin >> N >> M;
  gra.resize(N);
  cl.assign(N, -1);
  si.assign(N, 0);
  for (int i = 0; i < M; i ++) {
    int a, b;
    cin >> a >> b;
    a --;
    b --;
    gra[a].push(b);
    gra[b].push(a);
    si[a] ++;
    si[b] ++;
  }
  if (dfs(0, 0)) {
    int kj = 0;
    for (int i = 0; i < N; i ++) {
      kj += cl[i];
      //cout << cl[i] << endl;
    }
    //cout << kj << endl;
    long long ans = (long long)kj * (N - kj);
    long long m = (long long)M;
    cout << ans - m << endl;
  }
  else {
    long long ans = (long long)N * (N - 1);
    ans /= 2;
    long long m = (long long)M;
    cout << ans - m << endl;
  }
}

