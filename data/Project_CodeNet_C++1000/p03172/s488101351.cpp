#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;
const ll INF = 1e9+5;

int dp[100005];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	dp[0] = 1;
	for (int i=0 ; i<n ; i++) {
		int x;
		scanf("%d", &x);
		int sum = 0;
		for (int j=k ; j>=max(0, k-x) ; j--) {
			sum = (sum + dp[j]) % MOD;
		}
		for (int j=k ; j>=0 ; j--) {
			int o = dp[j];
			dp[j] = sum;
			sum -= o;
			if (sum < 0) sum += MOD;
			if (j-x-1 >= 0) sum=(sum+dp[j-x-1]) % MOD;
		}
		/*for (int j=0 ; j<=k ; j++) {
			cout <<dp[j]<<" ";
		}
		cout <<"\n";*/
	}
	printf("%d\n", dp[k]);
	return 0;
}