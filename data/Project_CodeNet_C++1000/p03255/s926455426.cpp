#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <stack>
#include <queue>
#include <set>
#include <list>
#include <bitset>
#include <array>

using namespace std;

#define fi first	
#define se second
#define long long long
typedef pair<int,int> ii;

const long BIG = 4e18;

int n;
long X;
long A[400003];
long pref[400003];
long RSQ(int a, int b)
{
	return (a > 0)? pref[b]-pref[a-1] : pref[b];
}
long sum(long a, long b)
{
	if(BIG-b < a) return BIG;
	else return a+b;
}
long mul(long a, long b)
{
	if(BIG/b < a) return BIG;
	else return a*b;
}
long f(long i)
{
	if(i == 1) return 5;
	else return 2*i+1;
}

int main()
{
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("input.in", "r", stdin);

	scanf("%d %lld", &n, &X);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &A[i]);
	
	for(int i = 1; i <= 400000; i++)
		pref[i] = pref[i-1]+A[i];

	long res = BIG;
	for(int i = 1; i <= n; i++)
	{
		long cnt = i*X;
		long idx = n;
		long no = 1;
		while(idx > 0)
		{
			cnt = sum(RSQ(idx-i+1,idx)*f(no),cnt);
			idx -= i;
			no++;
		}
		// printf("%d %lld\n", i, cnt);
		res = min(res,cnt);
	}
	printf("%lld\n", sum(res,n*X));
}









