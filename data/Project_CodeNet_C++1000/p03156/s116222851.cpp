#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(int argc, char const *argv[])
{
	int n, a, b; cin >> n >> a >> b;
	vector<int> p(n); rep(i, n) cin >> p[i];
	sort(p.begin(), p.end());

	int d1 = 0, d2 = 0, d3 = 0;
	for (auto u : p) {
		if (u <= a) d1++;
		else if (u <= b) d2++;
		else d3++;
	}
	cout << min({d1, d2, d3}) << endl;
	return 0;
}
