#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll N;
  ll A[5];
  cin >> N >> A[0] >> A[1] >> A[2] >> A[3] >> A[4];
  sort(A,A+5);
  ll ans = 4 + ((N + A[0] - 1)/A[0]);
  cout << ans << endl;
  return 0;
}