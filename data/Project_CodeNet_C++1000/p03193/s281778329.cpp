#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, H, W;
  cin >> N >> H >> W;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
  int ans = 0;
  for (int i = 0; i < N; i++) if (A[i] >= H && B[i] >= W) ans++;
  cout << ans << endl;
}