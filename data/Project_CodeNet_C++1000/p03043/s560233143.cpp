#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  double ans =0;
  for (int i =1; i<=N; i++) {
    int a =i;
    int b =0;
    while (a < K) {
      a *= 2;
      b++;
    }
    ans += pow(1.0 / 2,b) / N;
  }
  cout << fixed << setprecision(12) << ans << endl;
}