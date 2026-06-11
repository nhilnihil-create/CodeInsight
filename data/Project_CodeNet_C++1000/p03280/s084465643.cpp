#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int mian_ji = a * b;
	mian_ji = mian_ji - a - b + 1;
	printf("%d\n", mian_ji);
}