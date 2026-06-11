#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,K;
  cin >> N >> K; 
  long double ans = 0.0;
  for (int i = 1; i <= N; i++) {
    int a = i;
    int cnt = 0;
    for (int j = a; j < K; j*=2) {
      cnt++;
    }
    long double res = 1 / (long double)(N);
    res *= 1 / (long double)pow(2,cnt);
    ans += res;
  }
  cout << setprecision(120) << ans << endl;
  return 0;
}