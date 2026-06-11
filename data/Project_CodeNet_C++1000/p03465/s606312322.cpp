#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ri register int 
#define For(i,j,k) for(ri i=j;i<=k;i=-~i)
inline int v_in(){
    int f=1,sum=0;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){sum=(sum<<3)+(sum<<1)+(ch^48);ch=getchar();}
    return sum*f;
}
const int M=3e3+5;
int n,tot,a[M],sum,ans[M*M];bitset<M*M>b;
int main(){
	n=v_in();For(i,1,n)sum+=(a[i]=v_in());
	b[0]=1;For(i,1,n)b|=(b<<a[i]);
	For(i,1,sum)if(b[i])ans[++tot]=i;
	printf("%d\n",ans[(1+tot)/2]);
	return 0;
}