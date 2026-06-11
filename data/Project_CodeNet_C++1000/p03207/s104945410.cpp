#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  int MA = 0;
  int X, sum;
  sum = 0;
  rep(i, N) {
    cin >> X;
    sum += X;
    MA = max(MA, X);
  }
  cout << sum - MA / 2 << endl;
}