#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
constexpr auto INF = 2000000000;
constexpr auto MOD = 1000000007;

int main() {
	int h, w;
	cin >> h >> w;
	vvi a(h, vi(w));
	rep(i, h)rep(j, w) cin >> a[i][j];

	rep(i, h) if (i % 2)reverse(all(a[i]));

	vi y = {};
	vi x = {};
	vi yy = {};
	vi xx = {};


	rep(i, h)rep(j, w) {

		if (i == h - 1 && j == w - 1)continue;

		int ni, nj;
		if (j == w - 1) {
			ni = i + 1;
			nj = 0;
		}
		else {
			ni = i;
			nj = j + 1;
		}

		if (a[i][j] % 2) {

			y.push_back(i + 1);
			yy.push_back(ni + 1);

			if (i % 2)x.push_back(w - j);
			else x.push_back(j + 1);

			if (ni % 2)xx.push_back(w - nj);
			else	xx.push_back(nj + 1);

			a[ni][nj]++;
		}
	}

	cout << y.size() << endl;
	rep(i, y.size()) cout << y[i] << " " << x[i] << " " << yy[i] << " " << xx[i] << endl;
}