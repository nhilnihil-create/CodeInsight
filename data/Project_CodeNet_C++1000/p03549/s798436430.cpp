#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	int x = 0;
	int cnt = 1;
	rep(i, m) cnt *= 2;
	
	x += ((n-m) * 100 + m * 1900) * cnt;
	cout << x << endl;
	return 0;
}