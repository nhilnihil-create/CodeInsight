#include<bits/stdc++.h>
#define f(i,a,b) for(register int i(a);i<=b;i=-~i)
using namespace std;
inline int read(){
	int X(0);bool d(0);char ch(0);
	while(!isdigit(ch)) d|=ch=='-',ch=getchar();
	while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	return d?-X:X;
}
const int maxn=2e3+3;
int a,n,s[maxn*maxn],cnt,sum;
bitset<maxn*maxn>b;
int main(){
	int n=read();
	b[0]=1;
	f(i,1,n) a=read(),sum+=a,b|=b<<a;
	f(i,sum+1>>1,sum) if(b[i]) return printf("%d\n",i),0;
	return 0;
}