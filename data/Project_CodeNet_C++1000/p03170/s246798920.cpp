#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, k;
vector<int> v;
int dp[100005];


void solve()
{
	for (int i = 1; i <= k; ++i)
	{
		if(dp[i] >= 0)
			continue;

		int res;
		for (int j = 0; j < n; ++j)
		{
			int tam = (i - v[j]);
			if(tam < 0)
				continue;
			res = dp[tam];
			if(res == 1)
			{
				dp[i] = 2;
			}
			else if(res == 2)
			{
				dp[i] = 1;
				break;
			}
		}

	}

}


int main()
{

	cin >> n >> k;


 	memset(dp, -1, sizeof(dp));
 
 	int num1, menor = 1000002;
 	for (int i = 0; i < n; ++i)
 	{
 		cin >> num1;
 		v.push_back(num1);
 		dp[num1] = 1;
 		menor = min(menor, num1);
 	}

 	for (int i = 0; i < menor; ++i)
 	{
 		dp[i] = 2;
 	}

 	solve();

 	if(dp[k] == 1 || dp[k] == 3)
 		cout << "First\n";
 	else
 		cout << "Second\n";


 






















    return 0;
}