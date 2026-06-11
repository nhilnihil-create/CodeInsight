#include <bits/stdc++.h>

#define loop(s, e, i) for (int i = s; i < e; ++i)
#define print(s) cout << s << endl;
using namespace std;
using ll = long long;
using lld = long long;

/*
浮動小数点の入力
cout << fixed << setprecision(9) << endl;
*/

ll gcd(ll a, ll b)
{
  if (a < b)
  {
    return gcd(b, a);
  }
  while (b != 0)
  {
    ll tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

int main() {
  double N, K;
  cin >> N >> K;

  double result = 0;
  loop(1, N+1, i) {
    double score = K / i;
    if (score <= 1) {
      result += 1;
      continue;
    }
    int times = ceil(log2(score));
    result += 1.0/pow(2, times);
  }
  cout << fixed << setprecision(9) << result/N << endl;
}