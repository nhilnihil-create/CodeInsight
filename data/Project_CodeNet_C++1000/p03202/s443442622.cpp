#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=2e5+20;
const int inf=0x3f3f3f3f;

inline int power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=min((ll)ans*a,(ll)inf);
		b>>=1;
		a=min((ll)a*a,(ll)inf);
	}
	return ans;
}

int n,a[maxn];

inline void init()
{
	n=read();
	REP(i,1,n)a[i]=read();
}

#define pii pair<int,int>

inline bool check(int x)
{
	if(x==1)
	{
		REP(i,1,n-1)if(a[i]>a[i+1])return 0;
		return 1;
	}
	vector<pii>v;
	v.push_back(mkr(0,0));
	REP(i,1,n)
	{
			
		if(a[i]>v.back().fi)
		{
			v.push_back(mkr(a[i],0));
		}else
		{
			while(v.back().fi>a[i])v.pop_back();
			int ad=a[i];
			while(1)
			{
				if(ad!=v.back().fi)v.push_back(mkr(ad,0));
				if(v.back().fi==0)return 0;
				int len=SZ(v)-1;
				v[len].se++;
				if(v[len].se==x)
				{
					v[len].se=0; ad--;
					v.pop_back();
				}else
				{
					REP(j,ad+1,a[i])v.push_back(mkr(j,0));
					break;
				}
			}
		}
	}
	return 1;
}

inline void doing()
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}

int main()
{
	init();
	doing();
	return 0;
}
