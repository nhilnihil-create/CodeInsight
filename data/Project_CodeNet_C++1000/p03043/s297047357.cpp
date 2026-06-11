#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, K;
  cin >> N >> K;
  long double ans = 0.0;
  for (int i = 1; i <= N; i++)
  {
    long double temp = 1.0 / (long double)N;
    int now = i;
    while(now < K) {
      now *= 2;
      temp /= 2.0L;
    }
    ans += temp;
  }
  
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}
