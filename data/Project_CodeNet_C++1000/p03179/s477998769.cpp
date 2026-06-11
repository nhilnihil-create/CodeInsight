#include<bits/stdc++.h>
using namespace std;

int n;
string s;
vector<vector<int>> DP;
const int inf = (int)1e9 + 7;

int main()
{
	cin >> n >> s;

	// the idea is to case work the last element 
	// 4 <><
	// 1 < 3 > 2		4
	// 2 < 3 > 1		4
	// 1 < 4 > 2		3
	// 2 < 4 > 1		3
	// 3 < 4 > 1		2

	// if doing this way the only thing that matters is number of prefixes (satisfy requirements)
	// and the last element on the prefix (interface to the last element) the prefix of length len is using 1 ... len
	// 2D DP[len][j] array, len is the lengh of the prefix, and j is the last element in the prefix
	// len 1 ... n, j 1 ... n
	DP.resize(n + 1);
	for (int i = 2; i < n + 1; i++)
		DP[i].resize(n + 1, 0);
	DP[1].resize(n + 1, 1);
	// brute force approach
#if 0
	for (int len = 2; len < n + 1; len++)
	{
		for (int j = 1; j < len + 1; j++)
		{
			for (int k = 1; k < len + 1; k++)
			{
				// j is the last element that I am working on, k is the last element of the len-1 prefix
				// k can be anything from 0 to n-1, but k can't be same as j
				// if k and j not satisfy relation dont do anything
				if (k == j)
					continue;
				if ((s[len - 2] == '>' && k < j) || (s[len - 2] == '<' && k > j))
					continue;
				int k_sub = k;
				if (k > j)
					k_sub--;
				DP[len][j] = (DP[len][j] + DP[len - 1][k_sub]) % inf;
			}
		}
	}
#endif
	vector<int> psum;
	psum.resize(n+1, 0);
	for (int len = 2; len < n + 1; len++)
	{
		fill(psum.begin(), psum.end(), 0);
		for (int j = 1; j < len + 1; j++)
		{
			psum[j] = (psum[j - 1] + DP[len - 1][j])%inf;
		}
		for (int j = 1; j < len + 1; j++)
		{
			// either sum from 1 to j -1 or j+1 to len depend on the comparator from the string
			// so we can do prefix sum
			if(s[len-2]=='<')
				DP[len][j] = psum[j - 1];
			else if (s[len - 2] == '>')
				DP[len][j] = (psum[len-1] - psum[j-1]+inf)%inf;
		}
	}

	int total = 0;
	for (int j = 1; j < n+1; j++)
	{
		total = (total+DP[n][j])%inf;
	}
	cout << total << endl;
}