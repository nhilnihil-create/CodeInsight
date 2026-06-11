#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  vector<int> R[N];
  int num[N];
  int c[N];
  int ans[N];
  ll score = 0;
  for (int i = 0; i < N; i++) {
    num[i] = 0;
  }
  for (int i = 0; i < N - 1; i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    R[a].push_back(b);
    R[b].push_back(a);
    num[a]++;
    num[b]++;
  }
  for (int i = 0; i < N; i++) {
    cin >> c[i];
  }
  sort(c,c+N);
  for (int i = 0; i < N; i++) {
    int mxpoint = 99999;
    int mx = 99999;
    for (int j = 0; j < N; j++) {
      if (num[j] < mx) {
        mx = num[j];
        mxpoint = j;
      }
    }
    ans[mxpoint] = c[i];
    num[mxpoint] = 100000;
    score += c[i] * mx;
    for (int j = 0; j < R[mxpoint].size(); j++) {
      num[R[mxpoint][j]]--;
    }
  }
  cout << score << endl;
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}