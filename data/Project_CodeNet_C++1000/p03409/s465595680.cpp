#include<bits/stdc++.h>
#include<utility>
using namespace std;
bool ok(pair<int, int> a, pair<int, int> b) {
  if (a.first < b.first && a.second < b.second) return true;
  else return false;
}
int main () {
  int N;
  cin >> N;
  vector<pair<int, int>>A(N + 1);
  vector<pair<int, int>>B(N);
  vector<bool>ex(N + 1, true);
  for (int i = 0; i < N; i ++) {
    int a, b;
    cin >> a >> b;
    A[i] = make_pair(a, b);
  }
  A[N] = make_pair(-1, -1);
  ex[N] = false;
  for (int i = 0; i < N; i ++) {
    int a, b;
    cin >> a >> b;
    B[i] = make_pair(a, b);
  }
  sort(B.begin(), B.end());
  int ans = 0;
  for (int i = 0; i < N; i ++) {
    int k = N;
    for (int j = 0; j < N; j ++) {
      if (ok(A[j], B[i]) && A[j].second > A[k].second && ex[j])k = j;
    }
    if (ex[k]) {
      ans ++;
      ex[k] = false;
    }
  }
  cout << ans << endl;
}