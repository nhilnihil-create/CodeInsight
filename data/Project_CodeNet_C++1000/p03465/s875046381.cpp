#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

int n, sum, x;

bitset<N * N> s;

int main()
{
	scanf("%d", &n);
	s[0] = 1;
	for(int i = 1; i <= n; i++)
		scanf("%d", &x), s = s | (s << x), sum += x;
	sum = (sum + 1) / 2;
	for(int i = 1; i < N * N; i++)
		if(s[i] && i >= sum) { printf("%d", i); return 0; }
	return 0;
}