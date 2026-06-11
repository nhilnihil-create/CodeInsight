#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define D isdigit(c=tc())
		char c,*A,*B,FI[FS];
	public:
		I FastIO() {A=B=FI;}
		Tp I void read(Ty& x) {x=0;W(!D);W(x=(x<<3)+(x<<1)+(c&15),D);}
}F;
int q[N+5],d[N+5];I int BFS(CI x)
{
	RI i,k,f=0,H=1,T=1;for(i=1;i<=n;++i) d[i]=0;d[q[1]=x]=1;
	W(H<=T) for(i=lnk[k=q[H++]];i;i=e[i].nxt)
		!d[e[i].to]&&(d[q[++T]=e[i].to]=d[k]+1)>d[f]&&(f=e[i].to);return f;
}
int main()
{
	RI i,x,y;for(F.read(n),i=1;i^n;++i) F.read(x),F.read(y),add(x,y),add(y,x);
	return x=BFS(1),puts((d[BFS(x)]-2)%3?"First":"Second"),0;
}