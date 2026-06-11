#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define N 100001
vector<int> par(N);
vector<int> ranks(N);
vector<ll> sizes(N);

void init(int n)
{
	int i;
	rep(i,n)
	{
		par[i]=i;
		ranks[i]=0;
		sizes[i]=1;
	}
}

int find(int x)
{
	if(par[x]==x)return x;
	else return par[x] = find(par[x]);
}

void unite(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x==y)return;
	if(ranks[x]<ranks[y])
	{
		par[x] = y;
		sizes[y] += sizes[x];
	}
	else
	{
		par[y] = x;
		sizes[x] += sizes[y];
		if(ranks[x]==ranks[y])ranks[x]++;
	}
}

ll sizing(int x)
{
	return sizes[find(x)];
}

bool same(int x,int y)
{
	return find(x) == find(y);
}

ll c2(ll i)
{
	if(i==1) return 0;
	else return i*(i-1)/2;
}

int main()
{
	ll n,m;cin>>n>>m;
	vector<int> a(m);
	vector<int> b(m);
	int i;
	rep(i,m)cin>>a[i]>>b[i];
	vector<ll> count(m+1,0);
	init(n+1);
	for(i=m-1;i>=0;i--)
	{
		if(same(a[i],b[i]))
		{
			count[i]=count[i+1];
			continue;
		}
		ll bef=c2(sizing(a[i]))+c2(sizing(b[i]));
		unite(a[i],b[i]);
		ll aft=c2(sizing(a[i]));
		count[i]=count[i+1]+(aft-bef);
	}
	rep(i,m)count[i+1]=c2(n)-count[i+1];
	rep(i,m)cout<<count[i+1]<<endl;
}
