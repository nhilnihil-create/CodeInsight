#include<bits/stdc++.h>
using namespace std;
int n,k;
int f[100005];
int  a[105];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) 
	    scanf("%d",&a[i]);
	for(int i=1;i<=k;++i)
		for(int j=1;j<=n;++j)
			if(i >= a[j]&& !f[i-a[j]]) f[i]=1; 
	if(f[k]) printf("First\n");
	else printf("Second\n");
    return 0;
}