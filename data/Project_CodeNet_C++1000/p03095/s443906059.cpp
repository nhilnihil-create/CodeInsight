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

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v(26);
	rep(i,n) v[s[i] - 'a']++;
	ll ans = 0;
	rep(i,n) {
		int c = s[i] - 'a';
		ll temp = 1;
		rep(j, 26) {
			if (j == c) v[j]--;
			else {
				temp = temp * (v[j] + 1);
				temp %= MOD;
			}
		}
		ans += temp;
		ans %= MOD;
	}
	cout << ans << endl;
}