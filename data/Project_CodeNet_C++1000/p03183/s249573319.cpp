#include <bits/stdc++.h>
#define ll long long
#define max_weight 20002 

using namespace std;
 
//ordened by weight and solidness
bool cmp(vector<ll> &a, vector<ll> &b)
{
	return a[0] + a[1] < b[0] + b[1];
}

	
int main()
{
 
	int n;
	cin >> n;

	vector<vector<ll>> a(n, vector<ll>(3));
	//ll a[n][3];

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	sort(a.begin(), a.end(), cmp);

	vector<ll> dp(max_weight);

	
	for (int i = 0; i < n; ++i)
	{
		for (ll aguenta = a[i][1]; aguenta >= 0; aguenta--)
		{
			dp[aguenta + a[i][0]] = max(dp[aguenta + a[i][0]], dp[aguenta] + a[i][2]);
		}


	}

	ll resp = -1;
	for (int i = 0; i < max_weight; ++i)
	{	
		resp = max(resp, dp[i]);
	}


	cout << resp << endl;

 
 
    return 0;
}