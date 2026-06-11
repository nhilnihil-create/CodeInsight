#include<iostream>
#include<stdio.h>
#include<fstream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<map>
#include<iomanip>
#include<cassert>
#include<complex>
#include<functional>
#include<list>
#include<cmath>
#include<stack>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
int n,m,par[100001],r[100001];
ll weight[100001];
void init()
{
	for (int i=0;i<n;i++) par[i]=i;
}
int find(int x)
{
	if (par[x]==x) return x;
	else
	{
		int parent=find(par[x]);
		weight[x]+=weight[par[x]];
		return par[x]=parent;
	}
}
bool same(int x,int y)
{
	return find(x)==find(y);
}
bool unite(int x,int y,ll w)
{
	int xp=find(x),yp=find(y);
	w=w-weight[y]+weight[x];
	if (xp==yp)
	{
		if (weight[yp]-weight[xp]==w) return true;
		else return false;
	}
	if (r[xp]>r[yp]) par[yp]=xp,weight[yp]=w;
	else par[xp]=yp,weight[xp]=-w,r[yp]++;
	return true;
}
int main()
{
	cin>>n>>m;
	init();
	for (int i=0;i<m;i++)
	{
		int l,r,d;
		cin>>l>>r>>d;
		l--; r--;
		if (!unite(l,r,d))
		{
			cout<<"No";
    		return 0;
		}
	}
	cout<<"Yes";
    return 0;
}