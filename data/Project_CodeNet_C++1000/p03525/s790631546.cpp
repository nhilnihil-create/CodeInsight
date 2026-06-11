#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
vi dy = { 0,0,1,-1 };
vi dx = { 1,-1,0,0 };
constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;



int main() {
	int n;
	cin >> n;
	vi gap(13, 0);
	rep(i, n) {
		int d;
		cin >> d;
		gap[d]++;
	}
	bool same = false;
	rep(i, 13)if (gap[i] >= 3)same = true;
	if (gap[0] > 0||gap[12]>=2)same = true;

	if (same) {
		cout << 0 << endl;
		return 0;
	}

	vi c = { 0,24 };
	bool mns = false;
	rep1(i, 11) {
		if (gap[i] == 0)continue;
		if (gap[i] == 1) {
			if (!mns) { c.push_back(i); mns = true; }
			else { c.push_back(24-i); mns = false; }
		}
		if (gap[i] == 2) {
			c.push_back(i);
			c.push_back(24-i);
		}
	}
	if (gap[12] == 1) {
		c.push_back(12);
	}

	sort(all(c));

	int ans = 12;

	rep(i, c.size() - 1) ans = min(ans, c[i + 1] - c[i]);
	
	cout << ans << endl;

}
