#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int N, T, A;
  cin >> N >> T >> A;
  int ans = 0;
  double nearest = 300000;
  for (int i = 1; i <= N; i++) {
    int H;
    cin >> H;
    if (abs(A-(T-H*0.006)) < nearest) {
      ans = i;
      nearest = abs(A-(T-H*0.006));
    }
  }
  cout << ans << endl;
  return 0;
}
