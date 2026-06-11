#include<cstdio>
const int N=2E5+10;
int n,h;
int a[N],p[N];
inline int gw(int x,int mod){
//	printf("%d %d\n",x,mod);
	if(!x) return 0;
	if(p[x]>=mod){
		p[x]-=mod;
		p[x-1]++;
		return gw(x-1,mod);
	}
	return 1;
}
inline int ck(int x){
	int now=0;
	for(int i=1;i<=n;i++) p[i]=0;
	for(int i=1;i<=n;i++){
		if(a[i]>n){
			now=a[i];
			continue;
		}
		if(a[i]>now){
			for(int i=1+now;i<=a[i];i++) p[i]=0;
			now=a[i];
		}else{
			p[now=a[i]]++;
			if(!gw(now,x)) return 0;
		}
	}
	return 1;
}
int main(){
//	freopen("C.in","r",stdin);
//	freopen("bl.out","w",stdout);
//	printf("1");return 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	h=2;
	for(int i=3;i<=n;i++){
		if(a[i]>a[h]&&a[h]>a[h-1]) a[h]=a[i];
		else a[++h]=a[i];
	}
	n=h;if(n==2&&a[n]>a[n-1]){printf("1");return 0;}
	int l=2,r=n,res=1;
	while(l<=r){
		int mid=l+r>>1;
		if(ck(mid)){
			res=mid;
			r=mid-1;
		}else l=mid+1;
	}
	printf("%d\n",res);
	return 0;
}