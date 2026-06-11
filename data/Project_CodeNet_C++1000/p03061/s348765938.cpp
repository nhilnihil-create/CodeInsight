#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>
#include<numeric>

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	rep(i, n) {
		cin >> a[i];
	}
	vector<int>L(n+1),R(n+1);
	L[0] = 0;
	R[0] = 0;
	rep(i, n) {
		L[i + 1] = gcd(L[i], a[i]);
	}
	rep(i, n) {
		R[i + 1] = gcd(R[i], a[n -1- i]);
	}
	vector<int>m(n);
	int ans = 0;
	rep(i, n) {
		
		m[i] = gcd(L[i], R[n - i-1]);
		
		ans = max(ans, m[i]);
	}
	cout << ans;
	return 0;
}