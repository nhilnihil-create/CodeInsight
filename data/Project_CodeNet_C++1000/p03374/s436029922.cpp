#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100005
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define mp make_pair
#define ff first
#define ss second

int n,m;
int val[maxn];
ll all,dis[maxn],sum1[maxn],sum2[maxn],mx1[maxn],mx2[maxn];

inline int read(){
	int x=0,f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline ll read_ll(){
	ll x=0,f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	n=read(),all=read_ll();
	for (int i=1;i<=n;i++) dis[i]=read_ll(),val[i]=read();
	for (int i=1;i<=n;i++) sum1[i]=sum1[i-1]+val[i];
	for (int i=n;i;i--) sum2[i]=sum2[i+1]+val[i];
	ll ans=0;
	for (int i=1;i<=n;i++) mx1[i]=max(mx1[i-1],sum1[i]-dis[i]),ans=max(ans,mx1[i]);
	for (int i=n;i;i--) mx2[i]=max(mx2[i+1],sum2[i]-(all-dis[i])),ans=max(ans,mx2[i]);
	for (int i=1;i<n;i++) ans=max(ans,sum1[i]-2*dis[i]+mx2[i+1]);
	for (int i=n;i>1;i--) ans=max(ans,sum2[i]-2*(all-dis[i])+mx1[i-1]);
	cout<<ans<<endl;
	return 0;
}
