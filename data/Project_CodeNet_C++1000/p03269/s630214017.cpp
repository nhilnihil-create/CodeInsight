#include <bits/stdc++.h>

using namespace std;

#define  input freopen("in.txt","r",stdin)
#define  output freopen("out.txt","w",stdout)

int main()
{
	//input;
	//output;

	int L;
	cin >> L;

	int N = 20;
	int tmp = 1<<20;

	while(tmp>L)
	{
		N--;
		tmp = 1<<N;
	}
	int M = (2*N) + __builtin_popcount(L)-1;
	printf("%d %d\n", N+1, M);
	for(int i = 0; i < N; i++)
	{
		printf("%d %d %d\n", i+1, i+2, (1<<i));
		printf("%d %d %d\n", i+1, i+2, 0);
	}
	int cost = 1<<N;
	for(int i = 0; i < N; i++)
	{ 
		if(L&(1<<i))
		{
			printf("%d %d %d\n", i+1, N+1, cost);
			cost+=(1<<i);
		}
	}
	return 0;
}