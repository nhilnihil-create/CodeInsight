#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
ll n,m;
priority_queue<ll,vector<ll>,greater<ll> >q;
ll ans=0;
struct node
{
	ll a,b;
	bool operator<(const node &w)const
	{
		return b>w.b;
	}
}e[200005];
int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		ll w=read();
		ans+=w;
		q.push(w);
	}
	for(int i=1;i<=m;i++)
	{
		e[i].a=read();
		e[i].b=read();
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++)
	{
//		cout<<e[i].b<<endl;
		if(e[i].b<=q.top())break;
		for(int j=1;j<=e[i].a;j++)
		{
			if(e[i].b<=q.top())break;
			ans-=q.top();
			ans+=e[i].b;
			q.push(e[i].b);
			q.pop();
		}
	}
	cout<<ans<<endl;
	return 0;
}