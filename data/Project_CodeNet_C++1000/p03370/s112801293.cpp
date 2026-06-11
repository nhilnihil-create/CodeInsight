#include <iostream>
using namespace std;

int main() {
  int N, X, m[101];
  cin >> N >> X;
  int S = 0, M = 1001001001;
  for (int i = 0; i < N; ++i){
    cin >> m[i];
    S += m[i];
    if (m[i] < M){
      M = m[i];
    }
}
  int ans = N+(X-S)/M;
  cout << ans << endl;
}