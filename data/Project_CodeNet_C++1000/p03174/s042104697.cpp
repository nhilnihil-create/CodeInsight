
// match n men with n women according to certain rules (adj matrix)
// connection at any moment, should depend on the current state (which men and women are left to match)
// state of women: use one/zero to describe each woman, you need n parameters to describe the state of all women/men, then you can do dp
// (2^n)^2 to describe states which is too much
// instead use men sequentially, and only record woman's state; if this way, woman's state can be used to deduce men's state
// 1D DP with 2^n states (bit mask) dont use n parameter, use 1 parameter with n bits 
// DP[i], i is a mask to describe which woman has been matched and which are remaining to match

#include<bits/stdc++.h>;
using namespace std;

int n;
vector<vector<int>> adj;
vector<long long> DP;
const int inf = (int)1e9 + 7;

int popcount(uint32_t m)
{
	int counter = 0;
	while (m != 0)
	{
		if (m & 1)
			counter++;
		m = m >> 1;
	}
	return counter;
}

int main()
{
	cin >> n;
	adj.resize(n);
	for (int i = 0; i < n; i++)
	{
		adj[i].resize(n);
		for (int j = 0; j < n; j++)
			cin >> adj[i][j];
	}

	DP.resize(1 << n, 0); //DP array with 2^n states;
	DP[0] = 1;
	for (int mask = 1; mask < (1 << n); mask++) // go over all states
	{
		// based on mask (availabitity of women) to deduce men's availability (always sequential)
		int a = n - popcount(mask); // first man left, if I match this man, I should reach a state DP[?] that has been calculated before
		for (int b = 0; b < n; b++) // iterate through woman and first available to match with a
		{
			if (adj[a][b] && ((mask >> b) & 1)) //a, b are connected, b is available
			{
				//match should mask bth woman as unavailable, also update counts
				DP[mask] = (DP[mask] + DP[mask & (~(1 << b))])%inf;    //new state, set bth woman as used
			}
		}
	}
	cout << DP[(1<<n)-1] << endl;
}