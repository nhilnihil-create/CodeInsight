#include<stdio.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
const int oo=999;
int L,n,m,x[80],y[80],z[80],S,T,bi[21],bm,bv[21],las;
inline void add(int xx,int yy,int zz){
	x[++m]=xx;
	y[m]=yy;
	z[m]=zz;
}
int main(){
	bi[0]=1;
	fo(i,1,20) bi[i]=bi[i-1]<<1;
	scanf("%d",&L);
	L--;
	S=n=1;
	fd(i,20,0) if (bi[i]<=L+1){//bi[i]<=L
		bm=i-1;
		break;
	}
	//printf("%d\n",bm);
	bv[bm+1]=S;
	fd(i,bm,0){
		bv[i]=++n;
		add(bv[i+1],bv[i],0);
		add(bv[i+1],bv[i],bi[i]);
	}
	las=bi[bm+1];
	fd(i,bm,0) if (las+bi[i]-1<=L){
		add(S,bv[i],las);
		las+=bi[i];
	}
	printf("%d %d\n",n,m);
	fo(i,1,m) printf("%d %d %d\n",x[i],y[i],z[i]);
	return 0;
} 