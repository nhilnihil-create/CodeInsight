#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, p;
	scanf("%d %d", &a, &p);
	int t1, t2, t3;
	ll sum = 0;
	sum += p / 2;
	t1 = p % 2;
	t2 = (a * 3) / 2;
	t3 = (t1 + ((a * 3) % 2)) / 2;
	sum += t2 + t3;
	printf("%lld\n", sum);
	return 0;
}