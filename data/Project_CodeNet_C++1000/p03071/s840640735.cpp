#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if(a - 1 > b) printf("%d\n", a + a - 1);
	else if(b - 1 > a) printf("%d\n", b + b - 1);
	else printf("%d\n", a + b);
	return 0;
}