
#include <bits/stdc++.h>

#define ll long long int
#define float long double
#define IoFast ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
const int maxn=2e5+20,mod=1e9+7;
int a[maxn];
int dp[maxn];
int rock[maxn];

int main () {
	IoFast;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dp[0] = dp[1] = 1;
	rock[a[1]] =rock[a[1]]+ dp[0];
	for(int i=2;i<=n;i++){
		if(a[i-1]!=a[i]){
			rock[a[i]] =(rock[a[i]] + dp[i - 1])%mod;
		}
		dp[i]=rock[a[i]];
	}
	cout << dp[n] << endl;
	return 0;
}
