#include <bits/stdc++.h>
#define ll long long


using namespace std;

const ll mod = 1e9 + 7;

vector<int> filho[100005];
ll dp[100005][2];


ll dfs(int pai, int cor, int pos)
{

	if(dp[pos][cor] > 0)
		return dp[pos][cor];

	for (int i = 0; i < (int)filho[pos].size(); ++i)
	{
		int viz = filho[pos][i];
		ll valor = 0;
		if(viz != pai)
		{
			if(cor == 0) // put color = white
			{
				valor += (dfs(pos, 0, viz) % mod);
				valor += (dfs(pos, 1, viz) % mod);
			}
			else if(cor == 1) // put color = black
			{
				valor += (dfs(pos, 0, viz) % mod);
			}

			//tem q multiplicar os resultados
			if(dp[pos][cor] == 0)	
				dp[pos][cor] = valor;
			else
				dp[pos][cor] = (dp[pos][cor] * valor) % mod;
		}
		
	}


	//se é folha
	if(dp[pos][cor] == 0)
		return dp[pos][cor] = 1;
	
	return dp[pos][cor];

}



	

int main()
{

	int n, u, v;
	cin >> n;

	
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> u >> v;

		filho[u].push_back(v);
		filho[v].push_back(u);
	}

	ll resp = (dfs(-1, 0, 1) + dfs(-1, 1, 1)) % mod;

	

	cout << resp << endl;





    return 0;
}