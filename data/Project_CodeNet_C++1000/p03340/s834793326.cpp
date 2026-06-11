#include<bits/stdc++.h>
using namespace std;
int n,a[1000010];
long long suma,sumb,ans;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f; 
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	int j=0;
	for(int i=1;i<=n;i++)
	{
		while((suma^a[j+1])==(sumb+a[j+1])&&j<n)
		{
			suma^=a[++j];
			sumb+=a[j];
		}
		ans+=j-i+1;
		suma^=a[i];
		sumb-=a[i];
	}
	cout<<ans;
} 