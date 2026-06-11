#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

void ABC104D()
{
	const int MOD = 1000000007;
	string S;
	cin >> S;
	int N = S.size();
	vl dpQ(N + 1);
	dpQ[0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		dpQ[i] = dpQ[i - 1];
		if (S[i - 1] == '?')
		{
			dpQ[i] *= 3;
			dpQ[i] %= MOD;
		}
	}
	vl dpA(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		dpA[i] = dpA[i - 1];
		if (S[i - 1] == 'A')
		{
			dpA[i] += dpQ[i - 1];
			dpA[i] %= MOD;
		}
		else if (S[i - 1] == '?')
		{
			dpA[i] *= 3;
			dpA[i] += dpQ[i - 1];
			dpA[i] %= MOD;
		}
	}
	vl dpB(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		dpB[i] = dpB[i - 1];
		if (S[i - 1] == 'B')
		{
			dpB[i] += dpA[i - 1];
			dpB[i] %= MOD;
		}
		else if (S[i - 1] == '?')
		{
			dpB[i] *= 3;
			dpB[i] += dpA[i - 1];
			dpB[i] %= MOD;
		}
	}
	vl dpC(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		dpC[i] = dpC[i - 1];
		if (S[i - 1] == 'C')
		{
			dpC[i] += dpB[i - 1];
			dpC[i] %= MOD;
		}
		else if (S[i - 1] == '?')
		{
			dpC[i] *= 3;
			dpC[i] += dpB[i - 1];
			dpC[i] %= MOD;
		}
	}
	cout << dpC[N] << endl;
}
int main()
{
	ABC104D();
	return 0;
}
