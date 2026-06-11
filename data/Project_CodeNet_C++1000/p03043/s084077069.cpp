#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  double ans = 0;
  for (int i = 1; i <= N; i++) {
    int cnt = 0, tmp = i;
    while (tmp <= K - 1) {
      cnt++;
      tmp *= 2;
    }
    ans += pow(0.5, cnt);
  }
  cout << setprecision(12) << ans / N << endl;
}