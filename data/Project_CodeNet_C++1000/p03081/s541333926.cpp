#include<iostream>
#include<string>
using namespace std;
#define N 200005

int n,q,ans;
string s;
char c[N];
bool dir[N];

bool to(int x,int to)
{
	for(int i=0;i<q;i++)
	{
		if(c[i]!=s[x]) continue;
		if(dir[i]) x++;
		      else x--;
		if(x==to) return 1;
		if(x==-1 || x==n) return 0;
	}
	return 0;
}

int main()
{
	
	cin>>n>>q;
	cin>>s;
	for(int i=0;i<q;i++)
	{
		cin>>c[i];
		char x;
		cin>>x;
		if(x=='R') dir[i]=1;
	}
	
	ans=n;
	int l=-1,r=n;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(to(mid,-1)) l=mid;
		          else r=mid;
	}
	ans-=r;
	l=-1,r=n;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(to(mid,n)) r=mid;
		         else l=mid;
	}
	ans-=n-r;
	cout<<ans<<'\n';
	
	return 0;
}