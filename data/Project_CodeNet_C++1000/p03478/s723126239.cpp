#include <iostream>
using namespace std;
int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int keta_sum = 0;
    int x = i;
    while (x > 0) {
      keta_sum += x%10;
      x /= 10;
    }
    if (A <= keta_sum && keta_sum <= B) {
      ans += i;
    }
  }
  cout << ans << endl;
  return 0;
}
