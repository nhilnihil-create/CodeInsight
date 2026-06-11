#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int lowbit(int x){return x&-x;}
int f1[1<<19],f2[1<<19],n,N,ans,a[1<<19];
bool cmp(int x,int y){return a[x]<a[y];}
signed main(){
	scanf("%lld",&n);
	N=1<<n;
	scanf("%lld",&a[0]);
	a[N]=-1;
	for (int i=1;i<N;i++){
		scanf("%lld",&a[i]);
        f1[i]=i,f2[i]=N;
		int x[4],y=i;
		while (y){
			int _i=i-lowbit(y);
			x[0]=f1[i],x[1]=f2[i];
			x[2]=f1[_i],x[3]=f2[_i];
			sort(x,x+4,cmp);
			f1[i]=x[3];
			f2[i]=x[2]==x[3]?x[1]:x[2];
			y-=lowbit(y);
		}
		ans=max(ans,a[f1[i]]+a[f2[i]]);
		printf("%lld\n",ans);
    }
}