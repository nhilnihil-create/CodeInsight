#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fill(name, val) memset(name, val, sizeof(name));
#define vll vector<ll>
#define vvll vector<vll>

/*	Author: 🆉🅴🅽🅾🅻🆄🆂	*/

ll n, dp[1001][10001];	vvll a(1001, vll(3));
bool cmp(vll& a, vll& b){
	return a[0] + a[1] < b[0] + b[1];
}
ll calc(ll i, ll w){
	if(i == n || w > 10000)	return 0;
	if(dp[i][w] != -1)	return dp[i][w];
	dp[i][w] = calc(i+1, w);
	if(a[i][1] >= w)	dp[i][w] = max(dp[i][w], a[i][2] + calc(i+1, w + a[i][0]));
	return dp[i][w];
}
int main(){
	cin>>n;	fill(dp, -1);
	for(ll i = 0; i < n; i++)	cin>>a[i][0]>>a[i][1]>>a[i][2];
	sort(a.begin(), a.begin() + n, cmp);
	cout<<calc(0, 0);
}

// Time: O()