#include<iostream>
#include<cstdio>
long long ans,sum[200050],arr[200050],xro[200050];
int n,l=1;
int main()
{
 	std::scanf("%d",&n);
 	for(register int i=1;i<=n;++i) std::scanf("%lld",&arr[i]),sum[i]=sum[i-1]+arr[i],xro[i]=xro[i-1]^arr[i];
 	for(register int r=1;r<=n;++r)
 	{
 		while((sum[r]-sum[l-1])!=(xro[r]^xro[l-1])) l++;
 		ans+=r-l+1;
    }
    std::printf("%lld",ans);
}

