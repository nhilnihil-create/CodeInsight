#include <bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/abc089/tasks/abc089_d

using P=pair<int,int>;

int h, w, d, q, c[90000];
P s[90000];

int main() {
	cin >> h >> w >> d;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			int a;
			cin >> a;
			a--;
			s[a] = make_pair(i, j);
		}
	for (int i = d; i < h * w; i++)
		c[i] = c[i - d] + abs(s[i].first - s[i - d].first)
				+ abs(s[i].second - s[i - d].second);
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << c[r] - c[l] << endl;
	}

}
