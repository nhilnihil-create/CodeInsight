#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	int mx = -1000;
	rep(i, n) {
		int X;
		cin >> X;
		mx = max(mx, X);
	}
	int mn = 1000;
	rep(i, m) {
		int Y;
		cin >> Y;
		mn = min(mn, Y);
	}
	if (x < mx && mn <= y && mx < mn) cout << "No War" << endl;
	else cout << "War" << endl;
}