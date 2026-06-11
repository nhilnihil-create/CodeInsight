#include<bits/stdc++.h>
using namespace std;
long long ans[1005];
int cnt;
long long calc(long long x)
{
	long long res=0;
	while(x)
	{
		res+=x%10;
		x/=10;
	}
	return res;
}
int main()
{
	long long now=1e15;
	now--;
	ans[cnt=1]=now;
	while(now)
	{
		long long bits=calc(now);int flag=0;
		for(long long j=1;!flag;j*=10)
		{
			for(int i=1;i<=9;i++) 
			{
				long long temp=now-(long long)i*j;
				if(temp*bits<=now*calc(temp)) {flag=1;now=temp;break;}
			}
		}
		if(now) ans[++cnt]=now;
	}
	sort(ans+1,ans+cnt+1);
	long long K;
	scanf("%lld",&K);
	for(int i=1;i<=K;i++) printf("%lld\n",ans[i]);
	return 0;
}