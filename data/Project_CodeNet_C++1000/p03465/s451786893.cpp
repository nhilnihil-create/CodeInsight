#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
#define ll long long

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int n,v;
int a[2010];
bitset<(int)4e6+10> dp;

int main(int argc, char** argv) {
	int i,j;
	int sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),sum+=a[i];
	dp=0;dp[0]=1;
	for(i=1;i<=n;i++)
		dp|=dp<<a[i];
	for(i=(sum+1)/2;i<=sum;i++)
		if(dp[i])
			break;
	printf("%d\n",i);
	return 0;
}

/*


3
1 2 1

2


1

58


*/
