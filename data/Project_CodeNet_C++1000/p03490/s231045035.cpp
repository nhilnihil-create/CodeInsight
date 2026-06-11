#include "bits/stdc++.h"
using namespace std;
bool dp[8000][16001][2];
int ori = 8000;
int main()
{
	string s;
	int tarx, tary, n, f = 0, tcount[2] = {0, 0};
	cin >> s >> tarx >> tary;
	s += 'T';
	n = s.size();
	for(; f < n && s[f] == 'F'; ++f){}
	dp[0][ori][0] = true;
	dp[0][ori + f][1] = true;
	for(int i = f, isx = true, fcount = 0; i < n; ++i)
	{
		if(s[i] == 'T')
		{
			for(int j = 0; j <= 16000; ++j)
			{
				if(dp[tcount[isx]][j][isx])
				{
					if(0 <= j - fcount)
					{
						dp[tcount[isx] + 1][j - fcount][isx] = true;
					}
					if(j + fcount <= 16000)
					{
						dp[tcount[isx] + 1][j + fcount][isx] = true;
					}
				}
			}
			++tcount[isx];
			fcount = 0;
			isx = !isx;
		}
		else
		{
			++fcount;
		}
	}
	printf(dp[tcount[0]][tary + ori][0] && dp[tcount[1]][tarx + ori][1] ? "Yes\n" : "No\n");
}