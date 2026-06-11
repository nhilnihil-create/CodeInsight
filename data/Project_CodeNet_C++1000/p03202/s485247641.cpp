#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<int, int> pp;
const int maxn = 200100;
int s[maxn];
int n;
map<int, int> v;
bool can(int x)
{
	v.clear();
	for(int i = 2; i <= n; i ++)
		if(s[i] <= s[i - 1])
		{
			v[s[i]] ++;
			int now = s[i];
			while(v[now] == x)
			{
				v.erase(now);
				now --;
				if(now < 1)
					return 0;
				v[now] ++;
			}
			map<int, int>::iterator nxt, it;
			for(it = v.lower_bound(now + 1); it != v.end(); nxt = it, it ++, v.erase(nxt));
		}
	return 1;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	bool asd = 0;
	s[0] = 0;
	for(int i = 1; i <= n; i ++)
	{
		cin >> s[i];
		if(s[i] <= s[i - 1])
			asd = 1;
	}
	if(!asd)
	{
		cout << 1 << endl;
		return 0;
	}
	//cout << can(3) << endl;
	int l = 2, r = n;
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(can(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << l << endl;
	return 0;
}
/*
10
1 7 4 1 10 8 1 1 3 3 
*/