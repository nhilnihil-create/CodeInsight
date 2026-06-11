#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

vector<int> V[2];
set<int> S[2][2];

string s;

int x, y;

int main()
{
	ios::sync_with_stdio(false);
	cin >> s >> x >> y;
	bool dir = 0;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != 'T')
			cnt++;
		else
		{
			V[dir].push_back(cnt);
			cnt = 0;
			dir ^= 1;
		}
	}
	if (cnt != 0)
		V[dir].push_back(cnt);
	S[0][0].insert(V[0][0]);
	S[0][1].insert(0);
	for (int i = 1; i < V[0].size(); i++)
	{
		for (set<int>::iterator it = S[0][0].begin(); it != S[0][0].end(); it++)
			S[1][0].insert(*it + V[0][i]), S[1][0].insert(*it - V[0][i]);
		S[0][0] = S[1][0];
		S[1][0].clear();
	}
	for (int i = 0; i < V[1].size(); i++)
	{
		for (set<int>::iterator it = S[0][1].begin(); it != S[0][1].end(); it++)	
			S[1][1].insert(*it + V[1][i]), S[1][1].insert(*it - V[1][i]);
		S[0][1] = S[1][1];
		S[1][1].clear();
	}
	if (S[0][0].find(x) != S[0][0].end() && S[0][1].find(y) != S[0][1].end())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;	
}
