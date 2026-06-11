#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
bool dp1[17000][4001];
bool ch1[17000][4001];
bool dp2[17000][4001];
bool ch2[17000][4001];
vector<int> vt;
int n, m;
bool func1(int ch, int x)
{
	if (x*2 >= vt.size())
	{
		if (ch == n) {
			return 1;
		}
		else
			return 0;
	}
	bool &ret = dp1[ch][x];
	if (ch1[ch][x])return ret;
	ch1[ch][x] = 1;
	ret = max(ret, func1(ch + vt[x*2], x + 1));
	if(x)
	ret = max(ret, func1(ch - vt[x*2], x + 1));
	return ret;
}
bool func2(int ch, int x)
{
	if (x*2+1 >= vt.size())
	{
		if (ch == m)
			return 1;
		else
			return 0;
	}
	bool &ret = dp2[ch][x];
	if (ch2[ch][x])return ret;
	ch2[ch][x] = 1;
	ret = max(ret, func2(ch + vt[x*2+1], x + 1));
	ret = max(ret, func2(ch - vt[x*2+1], x + 1));
	return ret;
}
int main()
{
	string a;
	cin >> a;
	int t = a.size();
	int cnt = 0;
	for (int i = 0; i < t; i++)
	{
		if (a[i] == 'F')
			cnt++;
		else
		{
			vt.push_back(cnt);
			cnt = 0;
		}
	}
	vt.push_back(cnt);
	scanf("%d %d", &n, &m);
	n += 8000; m += 8000;
	if (func1(8000, 0) && func2(8000, 0))
		puts("Yes");
	else
		puts("No");
}