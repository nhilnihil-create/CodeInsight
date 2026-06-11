#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (1LL << 55)
#define MOD (1000 * 1000 * 1000 + 7)
#define maxn 200111

typedef long long ll;
typedef long double ld;

char str[maxn];
int dp[1 << 26];
int num[maxn];
int pre[maxn];

int main(){
	int n;	
	scanf("%s", str + 1);
	n = strlen(str + 1);
	for(int i = 0; i < (1 << 26); i++)
		dp[i] = 1e9;

	dp[0] = 0;
	pre[0] = 0;
	for(int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] ^ (1 << (str[i] - 'a'));

	num[0] = 0;
	for(int i = 1; i <= n; i++){
		num[i] = 1e9;					
		num[i] = min(num[i], dp[pre[i]] + 1); // all characters even number of times
		for(int j = 0; j < 26; j++){		  // one character odd number od times
			int x = pre[i] ^ (1 << j);
			num[i] = min(num[i], dp[x] + 1);
		}
		dp[pre[i]] = min(dp[pre[i]], num[i]);
	}
	printf("%d\n", num[n]);
	return 0;
}