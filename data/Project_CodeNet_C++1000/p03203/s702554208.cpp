#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int H, W, N, X, Y, x, y, cnt, res;
set<int>st[200000];

int main() {
	cin >> H >> W >> N;
	for (int i = 0; i < N; ++i) {
		cin >> X >> Y;
		--X;
		--Y;
		st[Y].insert(X);
	}
	for (int i = 0; i < W; ++i) {
		st[i].insert(H);
	}
	res = intmax;
	while (true) {
		if (st[y].find(x + 1) != st[y].end()) {
			res = min(res, cnt + 1);
			break;
		}
		else {
			res = min(res, cnt + *st[y].lower_bound(x) - x);
			if (y == W - 1)break;
			++x;
			if (st[y + 1].find(x) == st[y + 1].end()) {
				++y;
			}
			++cnt;
		}
	}
	cout << res << endl;
}