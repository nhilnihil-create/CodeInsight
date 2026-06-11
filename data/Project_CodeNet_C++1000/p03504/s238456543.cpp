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

vvi prg;

int main() {
	int n, cc;
	cin >> n >> cc;

	prg.assign(cc, vi(100000, 0));

	rep(i, n) {
		int s, t, c;
		cin >> s >> t >> c;
		s--;t--;c--;

		prg[c][s]++;
		if (t < 99999)prg[c][t+1]--;
	}

	vi s(cc, 0);
	int ans = 0;

	rep(i, 100000) {

		int k = 0;

		rep(j, cc) {
			s[j] += prg[j][i];
			if (s[j] >= 1)k++;
		}

		ans = max(ans, k);

	}

	cout << ans << endl;

}