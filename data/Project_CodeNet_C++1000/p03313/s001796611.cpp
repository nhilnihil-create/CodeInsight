#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
struct number
{
	int f,s;
}a[1<<MAXN];
int n;
int main()
{
	n=read();
	for(int i=0;i<1<<n;i++)
	{	
		int x;
		x=read();
		a[i].f=x;
		a[i].s=-1<<30;
	}
	for(int j=0;j<n;j++)
		for(int i=0;i<1<<n;i++)
			if(i>>j & 1)
			{
				int x=i^(1<<j);
				number ans;
				ans.f=max(a[i].f,a[x].f);
				if(a[i].f>a[x].f)
					ans.s=max(a[i].s,a[x].f);
				else
					ans.s=max(a[i].f,a[x].s);
				//cout<<ans.f<<" "<<ans.s<<endl;
				a[i]=ans;
			}
	int ans=0;
	for(int i=1;i<1<<n;i++)
	{
		ans=max(ans,a[i].f+a[i].s);
		//cout<<a[i].f<<" "<<a[i].s<<endl;
		cout<<ans<<endl;
	}
	cout<<endl;
	return 0;
}