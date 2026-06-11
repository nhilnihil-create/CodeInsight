#include <bits/stdc++.h>
using namespace std;

const int N = 18;
using ii = pair<int, int>;
#define x first
#define y second

namespace my {
	ii merge(ii a, ii b) {
		a.y = max(a.y, b.x);
		if(a.y > a.x) swap(a.x, a.y);
		a.y = max(a.y, b.y);
		if(a.y > a.x) swap(a.x, a.y);
		return a;
	}
}

int n;
ii f[2][1 << N];

int main(int argc, char const *argv[])
{
	// freopen("in", "r", stdin);
	cin >> n;
	for(int i = 0; i < (1 << n); i++) {
		cin >> f[0][i].x;
	}
	int t = 1;
	for(int i = 0; i < 18; i++) {
		for(int j = 0; j < (1 << n); j++) {
			f[t][j] = f[t ^ 1][j];
			if(j >> i & 1) {
				f[t][j] = my::merge(f[t ^ 1][j ^ (1 << i)], f[t][j]);
			}
		}
		t ^= 1;
	}
	t ^= 1;
	int mx = 0;
	for(int i = 1; i < (1 << n); i++) {
		mx = max(mx, f[t][i].x + f[t][i].y);
		cout << mx << '\n';
	}
	return 0;
}