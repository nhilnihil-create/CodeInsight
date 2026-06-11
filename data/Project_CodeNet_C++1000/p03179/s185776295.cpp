#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 3001;
int nb[MAXN][MAXN];
int32_t main()
{
	int N;
	cin >> N;
	string s;
	cin >> s;
	nb[0][0] = 1;
	for (int i = 0 ; i < N - 1 ; i++)
	{
		if (s[i] == '>')
		{
			int sommeActu = 0;
			for (int j = i ; j >= 0 ; j--)
			{
				sommeActu+=nb[i][j];
				sommeActu%=MOD;
				nb[i + 1][j] = sommeActu;
			}
		}
		else
		{
			int sommeActu = nb[i][0];
			for (int j = 1 ; j <= i + 1; j++)
			{
				nb[i + 1][j] = sommeActu;
				sommeActu += nb[i][j];
				sommeActu %= MOD;
			}
		}
	}
	int total = 0;
	for (int i = 0 ; i < N ; i++)
	{
		total = (total + nb[N - 1][i]) % MOD;
	}
	cout<<total<<endl;
}