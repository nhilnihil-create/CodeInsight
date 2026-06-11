#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()

constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;

int main() {
	int n;
	cin >> n;

	vi p(0);

	rep1(i, n / 2) {
		if (i == 1)continue;
		bool prime = true;
		rep1(j, i - 1)if (j != 1 && i % j == 0)prime = false;
		if (prime)p.push_back(i);
	}

	map<int, int> div;

	rep(i, p.size()) {
		int pp = p[i];
		int k = 0;
		while (n / pp) {
			k += n / pp;
			pp *= p[i];
		}

		div[p[i]] = k;
	}


	map<int, int> slc;

	vi t = { 3,5,15,25,75 };

	rep(i, 5) {
		for (auto x : div)if (x.second >= t[i] - 1)slc[t[i]]++;
	}

	int ans = 0;

	ans += slc[75];

	ans += slc[25] * (slc[3] - 1);

	ans += slc[15] * (slc[5] - 1);

	ans += slc[5] * (slc[5] - 1) * (slc[3] - 2) / 2;

	cout << ans << endl;

}