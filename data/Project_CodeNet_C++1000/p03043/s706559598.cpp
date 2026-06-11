#include <bits/stdc++.h>
using namespace std;

int main() {
  double N,K;
  cin >> N >> K;
  double ans = 0;
  for(int i=1; i<=N;i++){
    double x=1.0/N , y = i;
		while (y < K) {
			y *= 2;
			x /= 2;
		}
		ans += x;
  }
  cout << fixed << setprecision(20) << ans << endl;
}
