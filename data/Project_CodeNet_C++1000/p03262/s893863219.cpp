#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
  	long long x;
  	cin >> n >> x;
  	long long a[n];
  	for (int i = 0; i < n; ++i)
      	cin >> a[i];
  	long long ans = abs(x - a[0]);
  	for (int i = 1; i < n; ++i)
    	ans = __gcd(ans, abs(x - a[i]));
  	cout << ans << "\n";
}