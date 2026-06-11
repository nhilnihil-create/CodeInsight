#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#define mk make_pair
#include<set>

using namespace std;

inline int read()
{
   int x=0,f=1;char ch=getchar();
   while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
   while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
   return x*f;
}

const int maxn = 2e5+1e2;

struct Node{
	int x,y;
};

map<pair<int,int>,int> mp;
set<int> s[maxn];
int n,m,num;
Node a[maxn];
int ans=1e9;

void dfs(int x,int y,int now)
{
	if (x>n || y>m) return;
	set<int> :: iterator it;
	it=s[y].lower_bound(x);
	int val = *it;
	val--;
	ans=min(ans,now+val-x);
	
//	cout<<now<<" "<<ans<<" "<<val<<" "<<x<<" "<<y<<" "<<mp[mk(x,y+1)]<<endl; 
	
	//while (1);
	if (mp[mk(x+1,y+1)] || mp[mk(x+1,y)]) 
	{
	   if (!mp[mk(x+1,y)])
	     dfs(x+1,y,now+1);
	}
	else dfs(x+1,y+1,now+1);
}
int main()
{
  n=read(),m=read(),num=read();
  for (int i=1;i<=m;i++) s[i].insert(n+1);
  for (int i=1;i<=num;i++)
  {
  	 a[i].x=read();
  	 a[i].y=read();
  	 s[a[i].y].insert(a[i].x);
  	 mp[make_pair(a[i].x,a[i].y)]=1;
  }
  dfs(1,1,0);
  cout<<ans+1;
  return 0;
}
