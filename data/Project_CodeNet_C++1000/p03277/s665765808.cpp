#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e5+100,S=1e5+1;
int n,a[N],s[N],tr[N<<1];
LL L;

void Add(int x)
{
	while(x<=S+S) tr[x]+=1,x+=(x&(-x));
}

LL Query(int x)
{
	LL ret=0;
	while(x>0) ret+=tr[x],x-=(x&(-x));
	return ret;
}

bool check(int x)
{
	LL ret=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i] <= x) s[i]=s[i-1]-1;
		else s[i]=s[i-1]+1;
		//cout<<s[i]<<endl;
	}
	memset(tr,0,sizeof(tr));
	Add(S);
	for(int i=1;i<=n;++i)
	{
		ret+=i-Query(S+s[i]);
		//cout<<Query(S+s[i])<<endl;
		Add(S+s[i]);
	}
	//cout<<x<<" "<<ret<<endl;
	return ret>=L/2+1;
}

int main()
{
	scanf("%d",&n);
	L=1ll*n*(n+1)/2;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	int l=0,r=1e9+100;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	printf("%d",r);
	return 0;
}