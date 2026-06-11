#include<bits/stdc++.h>
#define maxn 2011
using namespace std;
bitset<2000100> f;
int a[maxn],n,sum;
inline int read(){
	int res=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')res=res*10+ch-48,ch=getchar();
	return res;
}
int main(){
	n=read();
	for(register int i=1;i<=n;i++){
		a[i]=read();
		sum+=a[i];
	}
	f[0]=1;
	for(register int i=n;i>=1;i--){//01
		f|=f<<a[i];
		}
		for(register int i=sum+1>>1;i<=sum;i++){
			if(f[i]){
				cout<<i;
				return 0;
			}
		}
	return 0;
}