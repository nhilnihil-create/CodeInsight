#include<bits/stdc++.h>
#define max(a,b) (((a)>(b))?a:b)
#define min(a,b) (((a)<(b))?a:b)
#define int long long
using namespace std;
template<typename T>void read(T &x){
	x=0;int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-48;
	x*=f;
}
int x[1010],y[1010],ji[2],n,d[50];
signed main(){
//	freopen("t.in","r",stdin);
//	freopen("wa.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i)
		read(x[i]),read(y[i]),ji[(x[i]+y[i])&1]++;
	if(ji[0]&&ji[1]){puts("-1");return 0;}
	int uss=31;
	for(int i=1;i<=uss;++i)
		d[uss-i+1]=(1<<(i-1));
	if(ji[0]) uss++;d[uss]=1;
	cout<<uss<<endl;
	for(int i=1;i<=uss;++i)
		cout<<d[i]<<" ";
	cout<<endl;
	//0---29
	for(int i=1;i<=n;++i){
		int nx=0,ny=0;
		for(int j=1;j<=uss;++j){
			int dx,dy;
			if(x[i]>nx) dx=abs(nx+d[j]-x[i])+abs(y[i]-ny);
				else dx=abs(nx-d[j]-x[i])+abs(y[i]-ny);
			if(y[i]>ny) dy=abs(ny+d[j]-y[i])+abs(x[i]-nx);
				else dy=abs(ny-d[j]-y[i])+abs(x[i]-nx);
			if(dx<dy) {
				if(x[i]>nx) putchar('R'),nx+=d[j];
				else putchar('L'),nx-=d[j];
			}
			else{
				if(y[i]>ny) putchar('U'),ny+=d[j];
				else putchar('D'),ny-=d[j];
			}			 
		}
		cout<<endl;
		if(x[i]!=nx||y[i]!=ny) while(true) nx++;
	}
	return 0;
}
