// ABC_110_B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define forn(i, n) for(int i = 0; i < (int)n; ++i)

int main()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;

	vector<int> v(n), w(m);
	forn(i, n) cin >> v[i];
	forn(i, m) cin >> w[i];

	sort(v.begin(), v.end());
	sort(w.begin(), w.end());

	bool flag_1 = v[v.size()-1] < w[0];
	bool flag_2 = (v[v.size()-1] >= x) && (w[0] <= y);

	if(flag_1 && flag_2) cout << "No War" << "\n";
	else cout << "War" << "\n";

	return 0;
}