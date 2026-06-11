#include<iostream>
#include<cstdio>
using namespace std;
long long x,a[200005],h[200005],yh[200005],ans;
int main() {    
	int n;    
	scanf("%d",&n);    
	h[0]=0;
	yh[0]=0;    
	for(int i=1;i<=n;i++)    
	{        
		scanf("%d",&a[i]);        
		h[i]=h[i-1]+a[i];        
		yh[i]=yh[i-1]^a[i];    
	}    
	int l=1;    
	ans=0;    
	for(int r=1;r<=n;r++)    
	{        
		while((h[r]-h[l-1])!=(yh[r]^yh[l-1])) l++;        
		ans+=r-l+1;    
	}    
	printf("%lld\n",ans);
}