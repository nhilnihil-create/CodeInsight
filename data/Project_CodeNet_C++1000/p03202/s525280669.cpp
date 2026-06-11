#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200005;

int n;
int a[N];
vector<int> v;
bool inc()
{
	for(int i=2;i<=n;i++)
		if(a[i-1]>=a[i]) return 0;
	return 1;
}
inline bool ok(int x)
{
	int p[10005];
	memset(p,0,sizeof(p));
	for(int i=1;i<=v[0];i++)
		p[i]=1;
	for(int i=1;i<v.size();i++)
	{
		if(v[i]>v[i-1])
		{
			for(int j=v[i-1]+1;j<=v[i];j++)
				p[j]=1;
			continue;
		}
		for(int j=v[i]+1;j<=v[i-1];j++)
			p[j]=0;
		int u=-1;
		for(int j=v[i];j>=1;j--)
			if(p[j]!=x)
			{
				u=j;
				break;
			}
		if(u==-1) return 0;
		p[u]++;
		for(int j=u+1;j<=v[i];j++)
			p[j]=1;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(inc()) return cout<<"1\n",0;
	for(int i=1;i<=n;i++)
		if(a[i]<=10000) v.pb(a[i]);
	n=v.size();
	
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(ok(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<l<<'\n';
	
	return 0;
}