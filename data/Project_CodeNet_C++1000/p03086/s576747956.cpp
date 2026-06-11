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

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = i; j < n; j++) {
			if (s[j] == 'A' || s[j] == 'C' || s[j] == 'G' || s[j] == 'T') temp++;
			else {
				ans = max(ans, temp);
				break;
			}
		}
		if (temp != 0) ans = max(ans, temp);
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}