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
int n;
int m;
int sum[1000005];
int main(){
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		int a,b;
		a=read();
		b=read();
		sum[a]++;
		sum[b+1]--;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		sum[i]+=sum[i-1];
		if(sum[i]==m)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}