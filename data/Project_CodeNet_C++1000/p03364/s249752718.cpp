#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>

using namespace std;

const int N = 400;
bool dp[N][N];
char a[N][N];
int n;
int ans = 0;

int main() 
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int b = 0; b < n; b++)
	{
		dp[b][0] = true;	
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[(j + b) % n][i] != a[(i + b) % n][j])
				{
					dp[b][0] = false;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dp[i][j])
			{
				ans++;
			}
		}
	} 
	cout << ans * n<< endl;


	

}
