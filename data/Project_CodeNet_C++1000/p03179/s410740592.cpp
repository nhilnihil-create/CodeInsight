#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;
const ll INF = 1e9+5;

int dp[3005];

int main() {
	int n;
	scanf("%d", &n);
	string s;
	cin >>s;
	for (int i=0 ; i<n ; i++) dp[i] = 1;
	for (int i=0 ; i<n-1 ; i++) {
		if (s[i] == '<') {
			int sum = 0;
			for (int k=n ; k>=0 ; k--) {
				int o = dp[k];
				dp[k] = sum;
				sum = (sum + o) % MOD;
			}
		} else {
			int sum = 0;
			for (int k=0 ; k<=n ; k++) {
				sum = (sum + dp[k]) % MOD;
				if (k>=n-i-1) dp[k] = 0;
				else dp[k] = sum;
			}
		}
		/*for (int i=0 ; i<=n ; i++) {
			cout <<dp[i]<<" ";
		}
		cout <<endl;*/
	}
	printf("%d\n", dp[0]);
	return 0;
}