#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<queue>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')	{if(c=='-')	f=-1;	c=getchar();}
    while(c>='0'&&c<='9')	t=t*10+c-'0',c=getchar();
    return t*f;
}
inline void write(ll x){if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
string s;
int cnt [4],mx,mn;
int main()
{
	cin>>s;
	int len=s.length();
	For(i,0,len)	cnt[s[i]-'a']++;
	mx=max(cnt[0],max(cnt[1],cnt[2]));
	mn=min(cnt[0],min(cnt[1],cnt[2]));
	if(mx-mn>1)	puts("NO");else puts("YES");
}