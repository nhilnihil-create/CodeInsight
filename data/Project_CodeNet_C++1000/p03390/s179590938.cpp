#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<map>
#include<vector>
#include<ctime>
#include<stack>
#define mp make_pair
#define pa pair<int,int>
#define INF 0x3f3f3f3f
#define inf 0x3f
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ull unsigned long long

using namespace std;

inline ll read()
{
	long long f=1,sum=0;
	char c=getchar();
	while (c<'0' || c>'9')
	{
		if (c=='-')	f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*f;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if (a>b) swap(a,b);
		int ans=0;
		if (a==b)
			ans=2*a-2;
		else
		{
			int tmp=sqrt((ll)a*b);
			ans=(tmp-1)*2-1;
			if ((ll)tmp*tmp<(ll)a*b) ans++;
			if ((ll)tmp*(tmp+1)<(ll)a*b) ans++;
		}
		printf("%d\n",ans);	
	} 
	return 0;
}
