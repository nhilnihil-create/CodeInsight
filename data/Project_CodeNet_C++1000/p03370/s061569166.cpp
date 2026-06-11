#include <iostream>
using namespace std;
int main()
{
  int N, X;
  cin >> N >> X;
  int min_m = 1001;
  int ans = N;
  for (int i = 0; i < N; i++) {
    int m;
    cin >> m;
    if (m < min_m) min_m = m;
    X -= m;
  }
  ans += (X / min_m);
  cout << ans << endl;
  return 0;
}
