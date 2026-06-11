#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define ll long long
#define re register
#define inf 0x3f3f3f3f
using namespace std;
bitset<4000007>f;
inline int read(){
   int x=0,w=0;char ch=getchar();
   while (!isdigit(ch))w|=ch=='-',ch=getchar();
   while (isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
   return w?-x:x;
}
int main(){
	int sum=0;
	int n=read();f[0]=1;
	for (int i=1;i<=n;++i){
		int x=read();
		f|=f<<x;
		sum+=x;
	}
	for (int i=(sum+1)/2;i<=sum;++i)
		if (f[i]){
			printf("%d",i);
			return 0;
		}
	return 0;
}
