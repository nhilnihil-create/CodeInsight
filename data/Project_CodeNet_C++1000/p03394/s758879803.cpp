#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 20005;

int n,ans,tot;
int S[MAXN];

vector<int> cnt[2][3];

int main()
{
	cin >> n;
	if (n == 3)
	{
		puts("2 5 63");
		return 0;
	}
	for (int i = 4;i <= 30000;i++)
		if (i % 2 == 0 || i % 3 == 0)
			cnt[i % 2][i % 3].push_back(i);
	ans = 15000;
	while (ans > n && cnt[0][1].size() >= 3)
	{
		cnt[0][1].pop_back();
		cnt[0][1].pop_back();
		cnt[0][1].pop_back();
		ans -= 3;
	}
	while (ans > n && cnt[0][2].size() >= 3)
	{
		cnt[0][2].pop_back();
		cnt[0][2].pop_back();
		cnt[0][2].pop_back();
		ans -= 3;
	}
	while (ans > n && cnt[1][0].size() >= 3)
	{
		cnt[1][0].pop_back();
		cnt[1][0].pop_back();
		ans -= 2;
	}
	while (ans > n && cnt[0][1].size() && cnt[0][2].size())
	{
		cnt[0][1].pop_back();
		cnt[0][2].pop_back();
		ans -= 2;
	}
	for (int i = 0;i < cnt[0][1].size();i++)
		S[++tot] = cnt[0][1][i];
	for (int i = 0;i < cnt[0][2].size();i++)
		S[++tot] = cnt[0][2][i];
	for (int i = 0;i < cnt[1][0].size();i++)
		S[++tot] = cnt[1][0][i];
	S[++tot] = 2;
	S[++tot] = 3;
	while (ans < n)
	{
		S[++tot] = cnt[0][0].back();
		cnt[0][0].pop_back();
		ans++;
	}
	sort(S + 1,S + n + 1);
	for (int i = 1;i <= n;i++)
		cout << S[i] << ' ';
	cout << endl;
	return 0;
}