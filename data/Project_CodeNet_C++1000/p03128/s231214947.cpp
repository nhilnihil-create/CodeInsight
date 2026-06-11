#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 10000;

int main() {
	int n, m;
	cin >> n >> m;
	int a[9];
	rep(i, m) cin >> a[i];
	sort(a, a + m, greater<int>());

	int f[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	int dp[N + 1];
	dp[0] = 0;
	rep1(i, n) dp[i] = -1;
	rep1(i, n) {
		rep(j, m) {
			if(i >= f[a[j]]) {
				dp[i] = max(dp[i], dp[i - f[a[j]]] + 1);
			}
		}
	}

	string ans;
	int match = n;
	int remain = dp[n];
	while(match > 0) {
		rep(j, m) {
			if(match >= f[a[j]] && remain == dp[match - f[a[j]]] + 1) {
				ans += (char)(a[j] + '0');
				match -= f[a[j]];
				remain--;
				break;
			}
		}
	}
	
	cout << ans << endl;
}
