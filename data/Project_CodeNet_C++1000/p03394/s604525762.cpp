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
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it, len;
	fastio() {it=len=0;}
	inline char get()
	{
		if (it<len) return s[it++]; it=0;
		len=fread(s, 1, 100000, stdin);
		if (len==0) return EOF; else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while (c==' '||c=='\n') c=get();
		if (it>0) it--;
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
	ll r=0; bool ng=0; char c; c=_buff.get();
	while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
	if (c=='-') ng=1, c=_buff.get();
	while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
	return ng?-r:r;
}
template <class T> inline void putnum(T x)
{
	if (x<0) putchar('-'), x=-x;
	register short a[20]={}, sz=0;
	while (x) a[sz++]=x%10, x/=10;
	if(sz==0) putchar('0');
	for (int i=sz-1; i>=0; i--) putchar('0'+a[i]);
}
inline char getreal() {char c=_buff.get(); while (c<=32) c=_buff.get(); return c;}
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n;
vector<int> v, V;
vector<int> ans;
int fb[33];
bool used[30011];
int main()
{
	cin>>n;
	for (int i=2; i<=30000; i++)
	{
		if (i%2==0||i%3==0||i%5==0)
		{
			if (i==2||i==3||i==25) continue;
			v.PB(i);
		}
	}
	for (int i=0; i<v.size(); i++)
	{
		if (!fb[v[i]%30])
		{
			fb[v[i]%30] = v[i];
			used[i] = 1;
		}
		else V.PB(v[i]);
	}
	ans.PB(2);
	ans.PB(3);
	ans.PB(25);
	if (n>3)
	{
		n -= 4;
		while (true)
		{
			ll sum = 30;
			random_shuffle(V.begin(), V.end());
			for (int i=0; i<n; i++)
			{
				sum += V[i];
			}
			int lst = fb[(30-sum%30)%30];
			if (lst!=0)
			{
				for (int i=0; i<n; i++) ans.PB(V[i]);
				ans.PB(lst);
				break;
			}
		}
	}
	for (auto x:ans) puti(x);
	return 0;
}
