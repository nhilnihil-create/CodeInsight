#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
ll n, ans, d[25][25];
vector<ll> b, c;
string a;

ll g() {
	ll i, j, t;
	d[0][0] = 1;
	for (i = 0; i < b.size(); i++) {
		for (j = 0; j < c.size(); j++) {
			if (i == 0 && j == 0) continue;
			t = n * 2 - (i + j);
			d[i][j] = 0;
			if (i > 0 && a[t] == a[b[i]]) d[i][j] += d[i - 1][j];
			if (j > 0 && a[t] == a[c[j]]) d[i][j] += d[i][j - 1];
		}
	}
	return d[b.size() - 1][c.size() - 1];
}

void f(ll p) {
	if (p == n) {
		ans += g();
		return;
	}
	b.push_back(p);
	f(p + 1);
	b.pop_back();
	c.push_back(p);
	f(p + 1);
	c.pop_back();
}

int main()
{
	cin >> n;
	cin >> a;
	b.push_back(-1);
	c.push_back(-1);
	f(0);
	cout << ans << endl;
    return 0;
}
