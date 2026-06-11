#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
#define ULL unsigned long long
int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f*x;
}
#define MAXN 200005
#define INF 0x3f3f3f3f
int a[MAXN+5],b[MAXN+5];
int main(){
	LL sum=0;
	int n=read();
	for(int i=1;i<=n;i++)
		a[i]=read(),b[i]=read(),sum+=a[i];
	bool f=0;
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i]){
			f=1;
			break;
		}
	if(!f){
		puts("0");
		return 0;
	}
	int tmp=INF;
	for(int i=1;i<=n;i++)
		if(a[i]>b[i])
			tmp=min(tmp,b[i]);
	printf("%lld\n",sum-tmp);
	return 0;
}