#include <bits/stdc++.h>

typedef long long ll;

const int N = 2e5 + 5;

int n, cntbc;
char s[N];
ll ans;

int main()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = n; i >= 1; i--)
		if (s[i] == 'A') ans += cntbc;
		else if (s[i] == 'C' && s[i - 1] == 'B') cntbc++;
		else if (s[i] == 'C' || (s[i] == 'B' && s[i + 1] != 'C')) cntbc = 0;
	return std::cout << ans << std::endl, 0;
}