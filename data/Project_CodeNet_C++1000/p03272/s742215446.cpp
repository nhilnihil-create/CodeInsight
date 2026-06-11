#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<ctime>
#include<vector>
#include<queue>
#include<map>
#include<deque>
#include<stack>
#include<algorithm>
#define N 10005
using namespace std;
const int INF=0x7fffffff;
const double Pi=acos(-1);
int A[N];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d\n",n-k+1);
	return 0;
}
