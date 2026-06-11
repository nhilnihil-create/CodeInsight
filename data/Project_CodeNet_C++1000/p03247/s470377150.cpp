#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, int> pli;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MN = 1010;
int N;
int X[MN], Y[MN];

int main() {
	cin >> N;
	int st = -1;
	bool ok = 1;

	rep(i, N) {
		cin >> X[i] >> Y[i];
		int t = abs(X[i] + Y[i]) % 2;
		if (st == -1) {
			st = t;
		} else {
			if (st != t) {
				ok = 0;
			}
		}
	}

	if (!ok) {
		puts("-1");
		return 0;
	}

	vector<ll> vec;

	rep(i, 31) vec.eb(1LL << i);
	if (!st) vec.eb(1);

	vector<string> ans(N);

	rep(i, N) {
		if (!st) {
			++X[i];
			ans[i].pb('L');
		}

		ll p = X[i] + Y[i], q = X[i] - Y[i];

		for (int j = 30; j >= 0; --j) {
			int dec = (1 << j);
			if (p >= 0 && q >= 0) {
				p -= dec; q -= dec; ans[i].pb('R');
			} else if (p >= 0 && q < 0) {
				p -= dec; q += dec; ans[i].pb('U');
			} else if (p < 0 && q > 0) {
				p += dec; q -= dec; ans[i].pb('D');
			} else {
				p += dec; q += dec; ans[i].pb('L');
			}
		} 

		reverse(ALL(ans[i]));
	}

	int sz = vec.size();
	cout << sz << endl;
	rep(i, sz) {
		cout << vec[i] << (i == sz - 1 ? '\n' : ' ');
	}

	rep(i, N) {
		cout << ans[i] << endl;
	}

	return 0;
}