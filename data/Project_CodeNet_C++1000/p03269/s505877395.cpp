#include <cstdio>
#include <algorithm>
#define max_a 25
#define lim_n 20
#define lim_m 60
#define max_p 20
#define max_e 10000
using namespace std;
int q[max_p+1];
struct node{
	int u,v,w;
	node(){}
	node(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
};
node e[max_e+1];
struct note{
	int u,v,w,k,tg;
	note(){}
	note(int _u,int _v,int _w,int _k,int _tg):u(_u),v(_v),w(_w),k(_k),tg(_tg){}
};
note ext[max_e+1],ext2[max_e+1];
void add(note*ext,const int&l,const int&r,int&m){
	note x;
	for(int i=l; ++i<=r; ){
		x=ext[i];
		for(int j=x.w*x.k+x.tg; (j-=x.w)>=x.tg; e[++m]=node(x.u,x.v,j));
	}
}
int main(){
	int l;
	scanf("%d",&l);
	if(l<=lim_m){
		printf("2 %d\n",l);
		for(puts("1 2 0"); --l; printf("1 2 %d\n",l));
		return 0;
	}
	--l;
	for(int a=1,p,m,lst,w,n,tmp,k,k2; ++a<=max_a; ){
		for(q[p=1]=(tmp=l)%a,w=1; tmp/=a; q[++p]=tmp%a,w*=a);
		for(lst=p+1,reverse(q+1,q+p+1),q[0]=m=tmp=k=k2=0; q[--lst]==a-1; );
		for(int i=0; ++i<lst; tmp+=q[i]*w,ext[++k]=note(i+1,i+2,w/=a,a,0))
			q[i]&&(ext2[++k2]=note(1,i+1,w,q[i],tmp),1);
		n=lst+1;
		lst&&(ext2[++k2]=note(1,n,w,q[lst]+1,tmp),w/=a);
//		note x;
//		for(int i=0; ++i<=k2; printf("%d %d %d %d %d\n",x.u,x.v,x.w,x.k,x.tg))
//			x=ext2[i];
		for(int j=lst,v; ++j<=p; n=v,w/=a)
			ext[++k]=note(n,v=n+1,w,a,0);
		add(ext,0,k,m);
		add(ext2,0,k2,m);
		if(n<=lim_n&&m<=lim_m){
			printf("%d %d\n",n,m);
			for(int i=0; ++i<=m; printf("%d %d %d\n",e[i].u,e[i].v,e[i].w));
			return 0;
		}
	}
	return 0;
}