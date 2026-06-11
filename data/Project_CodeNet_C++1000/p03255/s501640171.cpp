#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=200010;
int a[N];
__int128 g[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=='-'?o=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return o*x;
}
int main() {
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++) a[i]=gi(),g[i]=g[i-1]+a[i];
    __int128 ans=1LL<<60;
    for(int i=1;i<=n;i++) {
	__int128 s=(g[n]-g[n-i])*5;
	int t=5,j=n-i;
	while(j-i>0) s+=(g[j]-g[j-i])*t,t+=2,j-=i;
	ans=min(ans,s+g[j]*t+1LL*i*x);
    }
    cout<<(long long)ans+1LL*n*x;
    return 0;
}