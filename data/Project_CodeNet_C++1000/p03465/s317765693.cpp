#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;

typedef pair <int, int> pii;

const int Inf = 100000;
const int mod = 1000000007;
const double Pi = acos(-1);

void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n;
int sum = 0;
bool dp[2005][100000];

int main()
{
	cin >> n;
	dp[0][0] = true;
	for(int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		sum += temp;
		for(int j = 99999; j >= 0; j--)
		{
			if(j + temp <= 99999)
				dp[i][j + temp] |= dp[i - 1][j];
			if(j - temp >= 0)
				dp[i][j - temp] |= dp[i - 1][j];
			else
				dp[i][temp - j] |= dp[i - 1][j];
		}
	}
	for(int i = 0; i <= 99999; i++)
	{
		if(dp[n][i])
		{
			cout << (sum + i) / 2;
			return 0;
		}
	}
}