#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int par[100005];

int h[100005];

void init(int n)
{
	for(int i=0;i<=n;i++)
	{
		par[i]=i;
		h[i]=0;
	}
}

int root(int x)
{
	if(par[x]==x)return x;
	else return par[x]=root(par[x]);
}

bool same(int x,int y)
{
	return root(x)==root(y);
}

void unite(int x,int y)
{
	x=root(x);
	y=root(y);
	if(x==y)return;
	if(h[x]<h[y])par[x]=y;
	else
	{
		par[y]=x;
		if(h[x]==h[y])h[x]++;
	}
}


int main()
{
	int n,m,p,a,b,sum=0;
	vector<int>v;
	cin>>n>>m;
	init(n);
	for(int i=0;i<n;i++)
	{
		cin>>p;
		v.push_back(p);
	}
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		unite(a,b);
	}
	for(int i=0;i<n;i++)
	{
		if(same(v[i],i+1))sum++;
	}
	cout<<sum<<endl;
	return 0;
}