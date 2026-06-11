#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  int ans = max(A, max(B, C));
  for (int i = 0; i < K; i++) {
  	ans = ans * 2;
  }
  ans = ans + A + B + C - max(A, max(B, C));
  cout << ans << endl;
  return 0;
}
