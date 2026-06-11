#include<bits/stdc++.h>
using namespace std;
int n;
int a[3005];
int ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	   scanf("%d",&a[i]),ans+=a[i]-1;
	printf("%d\n",ans);
	return 0;
 } 