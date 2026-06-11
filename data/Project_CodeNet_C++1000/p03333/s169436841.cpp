/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <LL,LL>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

LL n,a[100010],b[100010],now=0,res=0,ans;
multiset <pii> s,t;

void calc(int i)
{
	int x,y;
	if(i==0)
	{
		x=s.begin()->se;
		y=s.begin()->fi;
		s.erase(s.begin());
		t.erase(t.find({-x,y}));
	}
	else
	{
		x=-(t.begin()->fi);
		y=t.begin()->se;
		t.erase(t.begin());
		s.erase(s.find({y,x}));
	}
	if(x<=now&&now<=y) return;
	if(abs(now-x)<abs(now-y))
	{
		res+=abs(now-x);
		now=x;
	}
	else
	{
		res+=abs(now-y);
		now=y;
	}
}

int main()
{
	cin>>n;
	rep(i,n)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		s.insert({b[i],a[i]});
		t.insert({-a[i],b[i]});
	}
	for(int i=0,j=0;i<n;i++,j^=1) calc(j);
	res+=abs(now);
	ans=res;
	rep(i,n)
	{
		s.insert({b[i],a[i]});
		t.insert({-a[i],b[i]});
	}
	now=res=0;
	for(int i=0,j=1;i<n;i++,j^=1) calc(j);
	res+=abs(now);
	ans=max(ans,res);
	cout<<ans<<endl;
	return 0;
}