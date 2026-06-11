#include<cstdio>
#include<set>
#include<bitset>
#define ll long long
using namespace std;
bitset<4000100> st;
int main()
{
	int n;
	scanf("%d", &n);
	int sum = 0;
	st[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int q;
		scanf("%d", &q);
		sum += q;
		st |= (st << q);
	}
	sum++;
	sum /= 2;
	for (int i = sum; i <= 4000000; i++) {
		if (st[i]) {
			printf("%d", i);
			return 0;
		}
	}
}