#include <bits/stdc++.h>
#define MAXN 2005
#define SIZE 2000005
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int a[MAXN];
bitset<SIZE>b;
int main(){
	int n=read();
	b[0]=1;
	int sum=0;
	for (int i=1;i<=n;++i){
		a[i]=read();
		b|=b<<a[i];
		sum+=a[i];
	}
	for (int i=(sum+1)/2;i<=sum;++i){
		if (b[i]){
			return printf("%d\n",i),0;
		}
	}
	return 0;
}