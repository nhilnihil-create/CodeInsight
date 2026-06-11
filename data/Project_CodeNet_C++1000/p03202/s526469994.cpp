using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200010
#define ll long long
int n;
int a[N];
ll k[N],b[N];
bool eql(ll d,ll k,ll b){
	ll s=1;
	for (;k && d<=b && s*d<=b;k>>=1,d*=d)
		if (k&1)
			s*=d;
	return k==0 && s==b;
}
bool judge(int d){
	int tp=0;
	k[0]=b[0]=0;
	k[tp=1]=a[1],b[1]=0;
	for (int i=2;i<=n;++i)
		if (a[i-1]<a[i]){
			if (b[tp]==0)
				k[tp]+=a[i]-a[i-1];
			else
				k[++tp]=a[i]-a[i-1],b[tp]=0;
		}
		else{
			int t=a[i-1]-a[i];
			while (t){
				if (t>=k[tp])
					t-=k[tp--];
				else{
					k[tp]-=t;
					for (;b[tp] && t;--t)
						b[tp]/=d;
					t=0;
				}
			}
			b[tp]++;
			ll s=0;
			for (;tp>=1 && eql(d,k[tp],b[tp]);--tp){
				b[tp-1]++;
				b[tp]=0;
				s+=k[tp];
			}
			if (tp==0)
				return 0;
			if (s){
				k[++tp]=s;
				b[tp]=0;
			}
		}
	return 1;
}
int main(){
	scanf("%d",&n);
	bool ok1=1;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]),ok1&=(a[i-1]<a[i]);
	if (ok1){
		printf("1\n");
		return 0;
	}
	int l=2,r=1000000000,res=r;
	while (l<=r){
		int mid=l+r>>1;
		if (judge(mid))	
			r=(res=mid)-1;
		else
			l=mid+1;
	}
	printf("%d\n",res);
	return 0;
}