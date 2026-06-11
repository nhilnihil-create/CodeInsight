#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdio>

using namespace std;
using ll = long long;
using ull = unsigned long long;


#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a-1;i>=b;i--)

auto sumdig(ll num) {
	ll dig, sum;
	sum = 0;
	while (num) {
		dig = num % 10;
		sum = sum + dig;
		num = num / 10;
	}
	return sum;
}




int main() {

	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int ans = 0;

	rep(i, 0, n/r+1) {
		rep(j, 0, n/g+1) {
			int cur = i * r + g * j;
			if ((n - cur >= 0)
				&& (n - cur) % b == 0) {
				ans += 1;
			}
			
		}
	}

	cout << ans << endl;
	return 0;
}