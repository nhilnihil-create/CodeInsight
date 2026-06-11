#include<iostream>
#include<cstdlib>
#include<utility>
#include<tuple>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#include<queue>
#include<deque>
#include<bitset>
#include<cmath>
#include<map>
#include<iomanip>
using namespace std;
using ll = long long int;
const ll mod = 1e9 + 7;
#define rep(i, a, b) for(int i = a; i < b; i++)

int gcd(int, int);

int main() {
	
	int n, X;
	cin >> n >> X;

	vector<int> x(n);
	rep(i, 0, n) {
		cin >> x[i];
		x[i] = abs(X - x[i]);
	}

	if (n == 1) {
		cout << x[0] << endl;
		return 0;
	}

	int ans = gcd(x[0], x[1]);

	rep(i, 1, n) {
		ans = gcd(ans, x[i]);
	}

	cout << ans << endl;

	return 0;
}

//最大公約数(ユークリッド互除法)
int gcd(int m, int n) {
	ll temp;
	while (m % n != 0) {
		temp = n;
		n = m % n;
		m = temp;
	}
	return n;
}