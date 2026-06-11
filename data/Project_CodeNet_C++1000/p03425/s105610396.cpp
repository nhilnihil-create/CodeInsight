#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

char c[5] = {'M', 'A', 'R', 'C', 'H'};

void solve() {
	int n;
	cin >> n;
	vector<ll> nums(n);
	rep(i,n) {
		string s;
		cin >> s;
		char d = s[0];
		rep(j,5) {
			if (d == c[j]) nums[j]++;
		}
	}
	ll ans = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				ans += nums[i] * nums[j] * nums[k];
			}
		}
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}