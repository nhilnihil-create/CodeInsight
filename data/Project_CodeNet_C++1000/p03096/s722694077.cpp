#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define ll long long
#define REP(a,b,c) for(int a=b;a<=c;a++)
#define re register
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
inline int gi(){
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=200010,Mod=1e9+7;
int n,a[N],pre[N],lst[N],f[N];
int main(){
	n=gi();
	REP(i,1,n){
		a[i]=gi();
		pre[i]=lst[a[i]];lst[a[i]]=i;
	}
	f[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(pre[i] && pre[i]!=i-1)f[i]=(f[i]+f[pre[i]])%Mod;
	}
	printf("%d\n",f[n]);
	return 0;
}
