#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 200000 + 100;
int N, ans, A[maxn];

void Init()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
}

void Solve()
{
	sort(A+1, A+N+1);
	printf("%d ", A[N]);
	int mid = A[N] >> 1;
	ans = A[1];
	for(int i = 2; i < N; ++i)
		if(abs(A[i]-mid) <= abs(ans-mid))
			ans = A[i];
	printf("%d\n", ans);
}

int main()
{
	Init(), Solve();
}