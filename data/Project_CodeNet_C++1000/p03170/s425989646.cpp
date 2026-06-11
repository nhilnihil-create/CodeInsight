#include <iostream>
using namespace std;

const int mxN = 1e5 + 5, mxM = 105;
int dp[mxN], a[mxN];

int main() {
	int n;
	scanf("%d", &n);
	int k;
	scanf("%d", &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = k; i >= 0; --i) {
		bool can = false;
		for(int j = 1; j <= n; ++j) {
			if(a[j] + i <= k)
				can |= dp[i + a[j]] == false;
		}
		dp[i] = can;
	}
	if(dp[0])
		puts("First");
	else
		puts("Second");
}
