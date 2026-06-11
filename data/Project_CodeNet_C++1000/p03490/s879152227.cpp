#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
vector<vector<int>> vt;
int visited[16001],visited1[16001];
int main()
{
	memset(visited, -1, sizeof(visited));
	memset(visited1, -1, sizeof(visited1));
	string a;
	cin >> a;
	vt.resize(2);
	int ch = 0;
	int t = a.size();
	int cnt = 0;
	for (int i = 0; i < t; i++)
	{
		if (a[i] == 'F')cnt++;
		else {
			vt[ch].push_back(cnt);
			cnt = 0;
			ch ^= 1;
		}
	}
	if (cnt)
		vt[ch].push_back(cnt);
	vector<int> vt1;
	for (int i = 0; i < vt[0].size(); i++)
	{
		vector<int> gap;
		if (!i)vt1.push_back(8000);
		for (int y = 0; y < vt1.size(); y++)
		{
			if (visited[vt1[y] + vt[0][i]] != i)
			{
				visited[vt1[y] + vt[0][i]] = i;
				gap.push_back(vt1[y] + vt[0][i]);
			}
			if (i) {
				if (visited[vt1[y] - vt[0][i]] != i)
				{
					visited[vt1[y] - vt[0][i]] = i;
					gap.push_back(vt1[y] - vt[0][i]);
				}
			}
		}
		vt1 = gap;
	}
	vt1.clear();
	for (int i = 0; i < vt[1].size(); i++)
	{
		vector<int> gap;
		if (!i)vt1.push_back(8000);
		for (int y = 0; y < vt1.size(); y++)
		{
			if (visited1[vt1[y] + vt[1][i]] != i)
			{
				visited1[vt1[y] + vt[1][i]] = i;
				gap.push_back(vt1[y] + vt[1][i]);
			}
			if (visited1[vt1[y] - vt[1][i]] != i)
			{
				visited1[vt1[y] - vt[1][i]] = i;
				gap.push_back(vt1[y] - vt[1][i]);
			}
		}
		vt1 = gap;
	}
	int n, m;
	cin >> n >> m;
	n += 8000;
	m += 8000;
	int tt = vt[0].size() - 1;
	int tt1 = vt[1].size() - 1;
	if ((visited[n]==tt && visited1[m]==tt1))
		puts("Yes");
	else puts("No");
}