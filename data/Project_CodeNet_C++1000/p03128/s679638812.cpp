#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, e[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6}, le[10005], a[15];
bool v[10005];
string d[10005];
bool f(int p, int q) {
	int i, t1, t2;
	for (i = 0; i < d[p].size(); i++) {
		t1 = d[p][i] - '0';
		t2 = d[q][i] - '0';
		if (t1 > t2) return 1;
		if (t1 < t2) return 0;
	}
	return 1;
}
int main()
{
	int i, j, z;
	cin >> n >> m;
	for (i = 0; i < m; i++) scanf ("%d", &a[i]);
	sort(a, a + m);
	v[0] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < m; j++) {
			z = i - e[a[j]];
			if (z < 0 || !v[z]) continue;
			if (le[i] < le[z] + 1 || le[i] == le[z] + 1 && f(z, i)) {
				v[i] = 1;
				d[i] = d[z];
				le[i] = le[z] + 1;
				d[i].push_back((char)(a[j] + '0'));
			}
		}
	}
	cout << d[n];
    return 0;
}
