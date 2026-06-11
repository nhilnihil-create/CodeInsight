#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 10;
char s[maxn];
int sta[maxn], top, n;
ll ans;
void solve()
{
	ll ret = 0, cnt = 0;
	for(int i = 1; i <= top; ++i) 
		if(sta[i] == 1) 
		{
			ret += i;
			++cnt;
		}
	ret -= cnt * (cnt + 1) / 2;
	ans += ret;
	top = 0;
}
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; ++i)
	{;
		if(s[i] == 'A') sta[++top] = 0;
		else if(s[i] == 'B' && s[i + 1] == 'C') { sta[++top] = 1; ++i;}
		else solve();
	}
	solve();
	printf("%lld\n", ans);
	return 0;
}