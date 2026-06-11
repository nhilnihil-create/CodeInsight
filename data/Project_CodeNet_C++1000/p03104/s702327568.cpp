#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll A,B;
  cin >> A >> B;
  ll eft = A;
  ll right = B;
  if (A % 2 == 1) eft++;
  if (B % 2 == 0) right--;
  ll ans = 0;
  ll num = (right - eft + 1) / 2;
  if (A % 2 == 1) ans ^= A;
  if (B % 2 == 0) ans ^= B;
  if (num % 2 == 1) ans ^= 1;
  cout << ans << endl;
  return 0;
}