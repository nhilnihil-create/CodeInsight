//Love and Freedom.
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set> 
#define pa pair<int,int>
#define mp make_pair
#define ll long long
#define inf 20021225
#define N 200010
using namespace std;
int read()
{
	int s=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return f*s;
}
int a[N],n;
set<pa> st; int gg; 
void add(int x,int v)
{
	if(x<1)	return void(gg=1); pa tmp=*st.lower_bound(mp(x,0));
	if(tmp.first!=x)	st.insert(tmp=mp(x,0));
	else
	{
		st.erase(tmp); tmp.second++;
		if(tmp.second>=v)	add(x-1,v);
		else	st.insert(tmp);
	}
	while(st.upper_bound(tmp)!=st.end())
		st.erase(*st.rbegin());
}
int check(int x)
{
	gg=0; st.clear();
	for(int i=1;i<=n;i++)	if(a[i]<=a[i-1])
		add(a[i],x-1);
	if(gg)	return 0;
	return 1;
}
int solve()
{
	int l=2,r=n,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))	ans=mid,r=mid-1;
		else	l=mid+1;
	}
	return ans;
}
int main()
{
	n=read(); int flag=1; for(int i=1;i<=n;i++)	a[i]=read(),flag&=(a[i]>a[i-1]);
	if(flag)	return puts("1"),0; printf("%d\n",solve());
	return 0;
}
