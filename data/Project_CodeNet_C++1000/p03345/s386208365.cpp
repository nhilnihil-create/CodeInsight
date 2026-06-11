#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c;
ll k;
int main()
{
	scanf("%d%d%d", &a, &b, &c);
	scanf("%lld", &k);
	if(k & 1) printf("%d\n", b - a);
	else printf("%d\n", a - b);
	return 0;
}