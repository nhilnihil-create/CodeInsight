#include <bits/stdc++.h>
#define ll long long 


using namespace std ;


//////////////////nao entendi por que guloso nao da certo///////////////
///////////so achar os dois adjacentes menores/////////////

vector<ll> sum;
ll dp[405][405];


ll cost(int i, int j)
{
	if(i - 1 >= 0)
	{
		return sum[j] - sum[i-1];
	}

	return sum[j];
}

ll solve(int l, int c)
{
	if(dp[l][c] >= 0)
		return dp[l][c];

	if(l == c)
		return dp[l][c] = 0LL;

	dp[l][c] = 999999999999999;
	for (int i = l; i <= c; ++i)
	{
		dp[l][c] = min(dp[l][c], solve(l, i) + solve(i+1, c) + cost(l, c));
	}

	return dp[l][c];

}


 
int main()
{
	int n;
	ll num;

	cin >> n;

	

	ll aux = 0LL;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		aux += num;
		sum.push_back(aux);
	}
 	
 	memset(dp, -1, sizeof(dp));
 	

	cout << solve(0, n - 1) << endl;
	 
}