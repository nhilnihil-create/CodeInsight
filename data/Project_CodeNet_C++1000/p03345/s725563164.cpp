#include<iostream>
using namespace std;
using ll = long long;

int main() {
  ll A, B, C, K;
  cin >> A >> B >> C >> K;

  ll ans = A - B;
  if (K % 2 == 1) ans = -ans;
  cout << ans << endl;
  return 0;
}
