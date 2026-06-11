#include<cstdio>
#include<algorithm>
using namespace std;
inline char tc(void){
	static char fl[10000],*A=fl,*B=fl;
	return A==B&&(B=(A=fl)+fread(fl,1,10000,stdin),A==B)?EOF:*A++;
}
inline int read(void){
	int a=0;char c;
	while((c=tc())<'0'||c>'9');
	while(c>='0'&&c<='9')a=a*10+c-'0',c=tc();
	return a;
}
int n,a[100005],mx,res=-1e9;
int main(void){
	register int i;
	n=read();
	for(i=1;i<=n;++i)a[i]=read(),mx=max(mx,a[i]);
	for(i=1;i<=n;++i)if(a[i]!=mx&&abs(res-(mx+1)/2)>abs(a[i]-(mx+1)/2))res=a[i];
	printf("%d %d\n",mx,res);
	return 0;
}