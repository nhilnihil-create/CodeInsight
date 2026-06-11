#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
typedef long long ll;
int n;
const int N=200005;
map<long long,int> mp;
long long a[N];
int id[N];
int fa[N],size[N];
bool cmp(int x,int y){return a[x]>a[y];}
int main()
{
//freopen("input.txt","r",stdin);
ios::sync_with_stdio(false);
cin.tie(0);
int n;
cin >>n;
rep(i,1,n)cin >>a[i],id[i]=i,mp[a[i]]=i,size[i]=1;
sort(id+1,id+1+n,cmp);
rep(i,1,n-1)
	{
	int x=id[i];
	fa[x]=mp[a[x]-n+2*size[x]];
	if(!fa[x])return cout <<-1,0;
	size[fa[x]]+=size[x];
	}
rep(i,1,n-1)
	{
	a[id[n]]-=size[id[i]];
	}
if (a[id[n]]) return puts("-1"),0;
rep (i,1,n-1) cout <<id[i]<<' '<<fa[id[i]]<<'\n';
return 0;
}
