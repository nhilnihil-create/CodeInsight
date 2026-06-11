#include<stdio.h>
#include<algorithm>
#define ll long long
using namespace std;
int a[15];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)  scanf("%d",&a[i]);
	sort(a,a+n);
	int sum=0;
	for(int j=0;j<n-1;j++)  sum+=a[j];
	if(sum>a[n-1])   printf("Yes\n");
	else if(sum<=a[n-1])   printf("No\n");    
	return 0;
}