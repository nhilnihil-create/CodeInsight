#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pss = pair<string, string>;
int n;
const int maxn = 50;
map<pss, int> M;
char s[maxn];
ll ans;
int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	int S = (1 << n) - 1;
	for(int i = 0; i <= S; ++i)
	{
		pss ret;
		for(int j = 0; j < n; ++j)
			if(i & (1 << j))
				ret.first += s[j];
			else 
				ret.second += s[j];
		++M[ret];
	}
	for(int i = 0; i <= S; ++i)
	{
		pss ret;
		for(int j = 0; j < n; ++j)
			if(i & (1 << j))
				ret.second += s[j + n];
			else
				ret.first += s[j + n];
		reverse(ret.first.begin(), ret.first.end());
		reverse(ret.second.begin(), ret.second.end());
		ans += M[ret];
	}
	printf("%lld\n", ans);
	return 0;
}