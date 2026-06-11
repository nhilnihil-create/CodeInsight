#include<cstdio>
#include<algorithm>
#define rg register
#define N 200010
using namespace std;
int n,m,a[N],mx=1e9,num;
inline int read(){
	int k=0,f=1; char c=getchar();
	while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while('0'<=c&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
int main(){
	n=read();
	for(rg int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n); int x=a[n];
	for(rg int i=1;i<=n;i++) 
		if(abs(x-2*a[i])<mx) mx=abs(x-2*a[i]),num=a[i];
	printf("%d %d\n",x,num);
	return 0; 
} 