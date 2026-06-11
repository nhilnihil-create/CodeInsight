#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int a[1<<18],n,N,f[1<<18][2],ans,sor[5];
bool cmp(int o,int oo){return a[o]>a[oo];}
int main(){
	n=read();N=1<<n;register int i,j,A,B;
	for(i=0;i<N;i++) a[i]=read();
	f[1][0]=0;f[1][1]=1;
	for(i=2;i<N;i++){
		f[i][0]=f[i][1]=i;
		for(j=17;j>=0;j--) if(i&(1<<j)){
			sor[1]=f[i^(1<<j)][0];sor[2]=f[i^(1<<j)][1];sor[3]=f[i][0],sor[4]=f[i][1];
			sort(sor+1,sor+5,cmp);
			f[i][0]=sor[1];f[i][1]=sor[2];
			if(f[i][0]==f[i][1]) f[i][0]=sor[3];
		}
	}
//	for(i=1;i<N;i++) printf("%d %d\n",f[i][1],f[i][0]);
	for(i=1;i<N;i++){
		ans=max(ans,a[f[i][1]]+a[f[i][0]]);
		printf("%d\n",ans);
	}
	return 0;
}