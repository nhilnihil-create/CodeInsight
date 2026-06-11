#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#define debug(a) cout << "*" << a << "*" << endl
using namespace std;
typedef long long ll;
ll m, n;
int main()
{
	while (~scanf("%lld%lld", &m, &n))
	{
		if (m == 1 && n == 1)
			printf("1\n");
		else if (m == 1 || n == 1)
			printf("%lld\n", max(m, n) - 2);
		else if (m == 2 || n == 2)
			printf("0\n");
		else
			printf("%lld\n", (m - 2) * (n - 2));
	}
}