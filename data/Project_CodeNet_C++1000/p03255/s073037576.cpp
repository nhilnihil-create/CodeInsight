#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <cmath>
#include <string>
#include <set>
#include <map>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int,int> P;

int A[SIZE];
int cost[SIZE];
int n,X;

ull solve(int k)
{
	ull ret=(ll) k*(ll) X;
	for(int i=n-1;i>=0;i--)
	{
		int c=n-i-1;
		ret+=(ll) cost[c/k]*(ll) A[i];
	}
	return ret;
}
int main()
{
	scanf("%d %d",&n,&X);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	cost[0]=5;
	for(int i=1;i<=n;i++) cost[i]=2*i+3;
	int l=1,r=n;
	while(r-l>5)
	{
		int d=(l+r)/2;
		if(solve(d)<solve(d+1)) r=d+1;
		else l=d;
	}
	ull ret=solve(l);
	for(int i=l;i<r;i++) ret=min(ret,solve(i));
	printf("%llu\n",ret+(ll) n*(ll) X);
	return 0;
}
