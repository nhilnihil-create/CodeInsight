#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005]; 
int gcd1[100005];
int gcd2[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	   scanf("%d",&a[i]);
	
	gcd1[1]=a[1];
	gcd2[n]=a[n];
	for(int i=2;i<=n;++i)
	    gcd1[i]=__gcd(gcd1[i-1],a[i]);//cout<<gcd1[i]<<" ";
	//cout<<endl;
	for(int i=n-1;i>=1;--i)
	    gcd2[i]=__gcd(gcd2[i+1],a[i]);//cout<<gcd2[i]<<" ";
	//cout<<endl;
	gcd1[0]=gcd2[2];
	gcd2[n+1]=gcd1[n-1];
	int ans=0;
	for(int i=1;i<=n;++i)
		ans=max(ans,__gcd(gcd1[i-1],gcd2[i+1]));
	printf("%d\n",ans);
	return 0;
}