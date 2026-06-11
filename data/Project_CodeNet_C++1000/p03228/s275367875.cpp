#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  ll A, B, K; cin >> A >> B >> K;

  for (int i = 0; i < K; ++i) {
    if (i%2) {
      if (B%2) B--;
      A += B/2;
      B /= 2;
    } else {
      if (A%2) A--;
      B += A/2;
      A /= 2;
    }
  }

  printf("%d %d\n", A, B);
}