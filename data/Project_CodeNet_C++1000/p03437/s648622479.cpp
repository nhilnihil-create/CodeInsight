#include <bits/stdc++.h>

int main()
{
	int64_t X, Y;
	scanf("%lld%lld", &X, &Y);
	if (X % Y == 0) puts("-1");
	else printf("%lld", X);

	return 0;
}