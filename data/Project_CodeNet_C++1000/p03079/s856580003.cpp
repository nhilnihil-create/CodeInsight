#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define met(s) memset(s, 0, sizeof(s))
const int MOD = 100000007;
const int MAXN = 1000000;
const int inf = 0x3f3f3f3f;
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a == b && b == c && a == c) printf("Yes\n");
	else printf("No\n");
	return 0;
}