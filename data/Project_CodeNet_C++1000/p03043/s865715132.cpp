#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
long double wss[18]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
int main(){
	long double n,m;
	n=read();
	m=read();
	long double ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i>=m)
		{
			ans+=(n-i+1)/n;
			break;
		}
		long double w=1.0/n;
		for(int j=0;j<=17;j++)
		{
			if(i*wss[j]>=m)
			{
				break;
			}
			w/=2;
		}
		ans+=w;
	}
	printf("%.12Lf\n",ans);
	return 0;
}