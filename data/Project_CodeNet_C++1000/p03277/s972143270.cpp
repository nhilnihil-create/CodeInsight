//QWsin
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define out(i,u) for(int i=first[u];i!=-1;i=next[i])

using namespace std;

const int INF=1<<30;

const int maxn=100000+10;

int a[maxn],t[maxn];

int n;
int C[maxn*2];

#define lowbit(x) ((x)&(-(x)))
inline void updata(int pos,int val){
	for(int i=pos;i<=n*3;i+=lowbit(i)) C[i]+=val;
}

inline int query(int pos){
	int ret=0;
	for(int i=pos;i;i-=lowbit(i)) ret+=C[i];
	return ret;	
}

typedef long long ll;

inline bool check(int mid)
{
	rep(i,1,2*n) C[i]=0;
	ll x=(1ll*n*(n+1)/2)/2+1,rk=0;
	int sum=0;
	
	updata(n+1,1);
	rep(i,1,n)
	{
		sum+= a[i]<mid?1:-1;
		rk+=query(sum+n);
		updata(sum+n+1,1);
	}
	
	return rk+1<=x;
}

int main()
{
	cin>>n;
	rep(i,1,n) scanf("%d",a+i),t[i]=a[i]; 
	sort(t+1,t+n+1);
	
	int l=1,r=n,mid,ans;
	
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(t[mid])) ans=t[mid],l=mid+1;
		else r=mid-1;	
	}
	
	cout<<ans<<endl;
	
	return 0;
}
