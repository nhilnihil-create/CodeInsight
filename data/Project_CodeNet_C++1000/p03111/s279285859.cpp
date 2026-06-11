#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void DFS(int& ans, int n, int a, int b, int c, vector<int>& v, const vector<int>& l)
{
	if (v.size() == n) {
		int mp = 0;
		int aa = 0, bb = 0, cc = 0;
		int cnta = 0, cntb = 0, cntc = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] == 0) aa += l[i], cnta++;
			else if (v[i] == 1) bb += l[i], cntb++;
			else if (v[i] == 2) cc += l[i], cntc++;
		}
		if (cnta == 0 || cntb == 0 || cntc == 0) return;
		mp += (max(0, cnta - 1) + max(0, cntb - 1) + max(0, cntc - 1)) * 10;
		mp += abs(a - aa) + abs(b - bb) + abs(c - cc);
		ans = min(ans, mp);
		return;
	}

	for (int i = 0; i < 4; i++) {
		v.push_back(i);
		DFS(ans, n, a, b, c, v, l);
		v.pop_back();
	}
}

int main()
{
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<int> l(n);
	for (int i = 0; i < n; i++) cin >> l[i];
	vector<int> v;
	int ans = INT_MAX;
	DFS(ans, n, a, b, c, v, l);
	cout << ans << endl;
}
