#include<bits/stdc++.h>
using namespace std;
int n, is = 1, num[200007];
map<int, int>mp;
int read()
{
	int num = 0;
	char c = getchar();
	while (c < '0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num;
}
int check(int mid)
{
	mp.clear();
	for (int i = 2; i <= n; i++)
		if (num[i] <= num[i - 1])
		{
			while (!mp.empty() && mp.rbegin()->first > num[i])
				mp.erase(mp.rbegin()->first);
			int pos = num[i];
			while (mp[pos] + 1 == mid)mp.erase(pos), pos--;
			if (!pos)return 0;
			mp[pos]++;
		}
	return 1;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		num[i] = read(), is &= (num[i] > num[i - 1]);
	if (is) { cout << 1 << endl; return 0; }
	int l = 2, r = n;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}