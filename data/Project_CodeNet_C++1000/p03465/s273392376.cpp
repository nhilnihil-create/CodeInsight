#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
const int N=2005;
int n;
int a[N];
int sta[N*N],len;
bitset<N*N+N>b;
int main(){
//	freopen("mid0.in","r",stdin);
//	freopen("mid.in","r",stdin);
//	freopen("mid.out","w",stdout);
	n=read();
	int sum=0;
	for(int i=1;i<=n;++i)sum+=(a[i]=read());
	b[0]=1;
	for(int i=1;i<=n;++i)b|=(b<<a[i]);
	for(int i=1;i<=sum;++i)if(b[i]==1)sta[++len]=i;
	printf("%d",sta[(len+1)/2]);
	return 0;
}