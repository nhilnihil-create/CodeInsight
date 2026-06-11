#include<cstdio>
#define Z int
#define S(n) scanf("%d",&n)
#define P(n) printf("%d",n)
#define F(i,a,b) for(Z i=a;i<=b;i++)
#define W while
#define sm(a,b) ((a)<(b)?(a):(b))
#define I if
#define E else
#define B break
#define R return
#define nx 200001
Z n,l,r,m,a[nx],no=0,inf=2e6;
Z num[nx],len[nx],t,dec,d,zr;
Z pw(Z x,Z y){
	Z s=1;
	W(y&&s<inf/x)s*=x,y--;
	R y?inf:s;
}
Z check(Z m){
	num[0]=num[t=1]=0,len[1]=a[1];
	F(i,2,n)I(a[i]>a[i-1])num[++t]=0,len[t]=a[i]-a[i-1];E{
		dec=a[i-1]-a[i];
		W(dec){
			W(num[t]&&dec)dec--,num[t]/=m,len[t]--,t-=!len[t];
			I(dec)d=sm(dec,len[t]),dec-=d,len[t]-=d,t-=!len[t];
		}
		num[t]++,zr=0;
		W(t&&num[t]==(d=pw(m,len[t])))zr+=len[t--],num[t]++;
		I(zr)num[++t]=0,len[t]=zr;
		I(num[0])R 0;
	}
	R 1;
}
Z main(){
	S(n);
	F(i,1,n)S(a[i]),no|=a[i]<=a[i-1];
	I(!no){P(1);R 0;}
	l=2,r=2e9;
	W(r-l>1)m=l+r>>1,check(m)?r=m:l=m;
	P(check(l)?l:l+1);
}