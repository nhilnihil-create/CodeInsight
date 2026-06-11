#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>
#define LL long long
#define rg register
using namespace std;
const LL MAXN=1000000LL;
LL N,p,tot,ans=1LL;
LL jl[MAXN],num[MAXN];

template<typename T>inline void in(T &a){
	T ch=getchar(),p=1;
	for(a=0;!isdigit(ch);ch=getchar()) if(ch=='-') p=-1;
	for(;isdigit(ch);ch=getchar()) a=a*10+ch-'0';
	a*=p;
}

template<typename T>inline void print(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar(x%10+'0');
}

inline LL calc(LL a,LL b){
	LL ans=1LL,base=a;
	while(b){
		if(b%2) ans*=base;
		base*=base;
		b/=2LL; 
	}
	return ans;
}

signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	in(N),in(p);

	if(N==1LL){
		print(p),puts("");
		return 0;
	}

	for(rg LL i=2LL;i<=sqrt(p);i++){
		if((p%i)!=0) continue;
		jl[++tot]=i;
		while((p%i)==0) num[i]++,p/=i;
		if(p==1LL) break;
	}
	
	for(rg int i=1;i<=tot;i++){
		if(num[jl[i]]>=N)
			ans*=calc(jl[i],num[jl[i]]/N);
	}
	
	print(ans),puts("");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1 111

3 24

1000000000000 1000000000000
*/