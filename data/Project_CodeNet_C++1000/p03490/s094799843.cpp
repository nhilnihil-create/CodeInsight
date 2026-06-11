#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;

#define INF 987654321
#define ll long long

string s;
vector<int> v[2];
int dp[16001][2]; //토글링
int X, Y;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	cin >> X >> Y;

	int cnt = 0, ty = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'F') cnt++;
		else
		{
			v[ty].push_back(cnt);
			cnt = 0;
			ty = 1 - ty;
		}
	}
	if (cnt) v[ty].push_back(cnt);

	//i = 0 예외 처리: 로봇은 처음에 오른쪽을 보고 있다.
	dp[8000 + v[0][0]][1] = 2;
	for (int i = 1; i < v[0].size(); i++)
	{
		for (int j = 0; j < 16001; j++)
		{
			if (dp[j][i % 2] == i + 1)
			{
				if (j + v[0][i] <= 16001)
					dp[j + v[0][i]][1 - i % 2] = i + 2;
				if (j - v[0][i] >= 0)
					dp[j - v[0][i]][1 - i % 2] = i + 2;
			}
		}
	}

	if (dp[X+8000][v[0].size() % 2] != v[0].size() + 1)
	{
		cout << "No";
		return 0;
	}

	for (int j = 0; j < 16001; j++)
		dp[j][0] = dp[j][1] = 0;

	dp[8000][0] = 1;
	for (int i = 0; i < v[1].size(); i++)
	{
		for (int j = 0; j < 16001; j++)
		{
			if (dp[j][i % 2] == i + 1)
			{
				if (j + v[1][i] <= 16001)
				{
					dp[j + v[1][i]][1 - i % 2] = i + 2;
				}
				if (j - v[1][i] >= 0)
					dp[j - v[1][i]][1 - i % 2] = i + 2;
			}
		}
	}

	if (dp[Y+8000][v[1].size() % 2] != v[1].size() + 1)
	{
		cout << "No";
		return 0;
	}
	
	cout << "Yes";
	return 0;
}