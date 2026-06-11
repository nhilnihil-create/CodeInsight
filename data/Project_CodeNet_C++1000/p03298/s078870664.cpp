//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
const ll mod=233231123112313ll;
int n;
ll ANS;
char s[40];
unordered_map<ll,int> mp1[20],mp2[20];
void solve(char s[])
{
	for(int i=0;i<(1<<n);i++)
	{
		ll hs=0;
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				(hs=1ll*hs*233+s[j])%mod;
				cnt++;
			}
		}
		for(int j=n-1;j>=0;j--)
		{
			if(!((i>>j)&1))(hs=1ll*hs*233+s[j])%mod;
		}
		mp1[cnt][hs]++;
	}
}
void query(char s[])
{
	for(int i=0;i<(1<<n);i++)
	{
		ll hs=0;
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				(hs=1ll*hs*233+s[j])%mod;
				cnt++;
			}
		}
		for(int j=n-1;j>=0;j--)
		{
			if(!((i>>j)&1))(hs=1ll*hs*233+s[j])%mod;
		}
		ANS+=mp1[cnt][hs];
	}
}

int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	solve(s);
	reverse(s+n,s+n+n);
	query(s+n);
	cout<<ANS<<endl;
	return 0;
}
