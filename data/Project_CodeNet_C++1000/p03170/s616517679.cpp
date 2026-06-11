#include <bits/stdc++.h>
using namespace std;
const int maxk = 1e5+5;
const int maxn = 100+5;
int A[maxn];
bool dp[maxk];
int main(int argc, char const *argv[])
{
	int n, k, x; scanf("%d%d", &n, &k);
	memset(dp, false, sizeof dp);
	for(int i = 0; i < n; i++){
		scanf("%d", &A[i]);
		dp[A[i]] = true;
	}

	for(int i = 1; i <= k; i++){
		if(!dp[i]){
			for(int j = 0; j < n; j++){
				if(i - A[j] >= 0 && !dp[i-A[j]]){
					dp[i] = true;
					break;
				}
			}
		}
	}

	if(dp[k]) printf("First\n");
	else printf("Second\n");
	return 0;
}