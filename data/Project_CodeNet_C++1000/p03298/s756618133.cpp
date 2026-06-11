#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,ans;
char ch[maxn];
map <pair<string,string>,int> p;

int main()
{
	n=read(); scanf("%s",ch+1); int ed=(1<<n)-1;
	rep(s,0,ed)
	{
		string t1="",t2="";
		rep(i,1,n) if(s&(1<<(i-1))) t1+=ch[i]; else t2+=ch[i];
		p[make_pair(t1,t2)]++;
	}
	rep(s,0,ed)
	{
		string t1="",t2="";
		per(i,n,1) if(s&(1<<(i-1))) t1+=ch[i+n]; else t2+=ch[i+n];
		ans+=p[make_pair(t2,t1)];
	}
	cout<<ans<<endl;
	return 0;
}