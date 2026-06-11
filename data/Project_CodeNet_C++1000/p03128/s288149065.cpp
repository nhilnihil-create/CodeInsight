#include <iostream>
#include <cstdio>
using namespace std;

int n, m, c[15] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
bool v[10005];
string a[15], d[10005];

string f(string p, string q) {
	if (p.size() > q.size()) return p;
	if (p.size() < q.size()) return q;
	if (p > q) return p;
	return q;
}

int main()
{
	int i, j, t;
	cin >> n >> m;
	for (i = 0; i < m; i++) cin >> a[i];
	v[0] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < m; j++) {
			t = c[a[j][0] - '0'];
			if (t <= i) {
				if (v[i - t]) v[i] = 1, d[i] = f(d[i], d[i - t] + a[j]);
			}
		}
	}
    cout << d[n] << endl;
    return 0;
}