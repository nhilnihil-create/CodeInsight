#include<iostream>
#include<cstdio>
using namespace std;
#define N 200012
int n,a[N],P[N],ans=0,f[N];
int main(){
	scanf("%d",&n);int i;for(i=1;i<=n;i++)scanf("%d",&a[i]),P[a[i]]=i;
	for(i=1;i<=n;i++)f[i]=f[P[a[i]-1]]+1,ans=max(ans,f[i]);printf("%d",n-ans);return 0;
}