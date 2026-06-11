#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N, H, W, ans = 0;
  cin >> N >> H >> W;
  vector<int> A(N), B(N);
  for (int i=0; i<N; i++) cin >> A[i] >> B[i];
  for (int i=0; i<N; i++) {
    if (A[i]>=H&&B[i]>=W) ans++;
  }
  cout << ans << endl;
}