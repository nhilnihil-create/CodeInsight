#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#define lowbit(x) x&-x
using namespace std;
typedef long long ll;
const int maxn = 400007;
const int N = 1e5;
int n,m;
ll tr[maxn];
int val[maxn];
int num[maxn],sum[maxn],c[maxn];

void add(int x,int num){
	for(;x<=n;x+=lowbit(x)){
		tr[x+N]+=num;
	}
}
ll query(int x){
	ll ret=0;
	for(;x;x-=lowbit(x)){
		ret+=tr[x+N];	
	}
	return ret;
}

ll calc(int l,int r,int x){
	memset(tr,0,sizeof(tr));
	for(int i=1;i<=n;i++){
		if(num[i]<=x)val[i]=1;
		else val[i]=-1;
	}
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+val[i];
		c[i]=sum[i];
	}
	c[n+1]=0;
	sort(c+1,c+1+n+1);int pos=unique(c+1,c+1+n+1)-c-1;
	for(int i=0;i<=n;i++)sum[i]=lower_bound(c+1,c+1+pos,sum[i])-c;
	
	ll ret=0;
	add(sum[0],1);
	for(int i=1;i<=n;i++){
		ret+=query(sum[i]-1);
		add(sum[i],1);
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	int l=1,r=1e9;
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	ll step=((1ll*n*1ll*(n+1)>>1 )>>1)+1,ans;
	while(l<=r){
		int mid=l+r>>1;
		//cout<<l<<" "<<r<<" "<<mid<<endl;
		if(calc(l,r,mid)>=step)ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
}