#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int n,m;
vector<int> siz;
vector<int> par;
int find(int node)
{
	while(node!=par[node])node=par[node];
	return node;
}
void uni(int a,int b)
{
	a=find(a);b=find(b);
	if(a==b)return;
	if(siz[a]<siz[b])swap(a,b);
	siz[a]+=siz[b];
	par[b]=a;
}
bool same(int a,int b)
{
	a=find(a);b=find(b);
	return a==b;
}
int32_t main()
{
	n=in();m=in();
	siz=vector<int>(n,1);
	par=vector<int>(n);
	iota(par.begin(),par.end(),0);
	int a[m],b[m];
	for(int i=0;i<m;i++)
	{
		a[i]=in();b[i]=in();
		a[i]--;b[i]--;
	}
	
	vector<int> ans;
	int t=n*(n-1);t/=2;
	ans.push_back(t);
	
	for(int i=m-1;i>=1;i--)
	{
		if(!same(a[i],b[i]))
		{
			t-=siz[find(a[i])]*siz[find(b[i])];
			uni(a[i],b[i]);
		}
		ans.push_back(t);
	}
	reverse(all(ans));
	for(auto i:ans)cout<<i<<'\n';
	
	
	
}