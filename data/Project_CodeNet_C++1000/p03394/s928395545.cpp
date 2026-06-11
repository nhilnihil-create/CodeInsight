#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF 1145141919364364
#define int long long
#define all(vec) vec.begin(),vec.end()
#define P pair<int,int>
#define S second
#define F first

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}

int n;
vector<int> ans;

signed main() {
	cin >> n;
	if (n == 3)cout << 2 << " " << 5 << " " << 63 << endl;
	else if (n == 4)cout << 2 << " " << 5 << " " << 20 << " " << 63 << endl;
	else {
		int cnt = 0;
		int k = 0;
		int b = 0;
		for (int i = 1;; i++) {
			if (!(i % 2) || !(i % 3)) {
				cnt += i;
				k++;
				ans.push_back(i);
			}
			if (k == n) {
				b = i;
				break;
			}
		}
		b++;
		if (cnt % 6 == 2) {
			ans.erase(ans.begin() + 0);
			for (int i = b;; i++) {
				if (!(i % 6)) {
					ans.push_back(i);
					break;
				}
			}
		}
		if (cnt % 6 == 3) {
			ans.erase(ans.begin() + 1);
			for (int i = b;; i++) {
				if (!(i % 6)) {
					ans.push_back(i);
					break;
				}
			}
		}
		if (cnt % 6 == 5) {
			ans.erase(ans.begin() + 0);
			for (int i = b;; i++) {
				if (i % 6 == 3) {
					ans.push_back(i);
					break;
				}
			}
		}
		for (int i = 0; i < (int)ans.size(); i++)cout << ans[i] << " ";
		cout << endl;
	}
}