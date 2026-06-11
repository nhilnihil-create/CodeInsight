#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define umap unordered_map
#define get(a, n)    for(ll i = 0; i < n; i++)    cin>>a[i];
#define error(x) fixed<<setprecision(x) //cout<<error(5)<<someDouble    -> example - 3.14159
ll n;	double p[3000];
umap<ll, umap<ll, double>> dp;
double solve(ll i, ll hc){	//index, head count
	if(i == n)	return (hc > i - hc);
	if(dp[i].count(hc))	return dp[i][hc];
	return dp[i][hc] = (1-p[i])*solve(i+1, hc) + p[i]*solve(i+1, hc+1);
}
int main(){
	cin>>n;	get(p, n);
	cout<<error(9)<<solve(0, 0);
}

// Time: O(N*N)
// Space: O(N*N)