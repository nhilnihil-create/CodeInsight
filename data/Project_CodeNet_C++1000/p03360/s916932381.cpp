#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B, C, K;
  cin >> A >> B >> C >> K;

  int max_v = max(max(A, B), C);
  int sum1 = A + B + C - max_v;
  int sum2 = max_v * pow(2, K);

  cout << sum1 + sum2 << endl;

  return 0;
}
