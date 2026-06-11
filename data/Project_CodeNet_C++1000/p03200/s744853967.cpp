#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
char s[maxn];
ll ans;
int main()
{
	scanf("%s", s + 1);
	for(int i = 1, j = 1; s[i]; ++i)
		if(s[i] == 'W')
		{
			ans += i - j;
			++j;
		}
	printf("%lld\n", ans);
	return 0;
}