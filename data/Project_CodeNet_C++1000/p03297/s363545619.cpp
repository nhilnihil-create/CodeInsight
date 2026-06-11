#include<bits/stdc++.h>
using namespace std;
#define N 200003
#define LL long long
#define mod 998244353

int T;
LL A,B,C,D;

inline int read(){
	int X=0,w=0;
	char ch=0;
	while (ch<'0' || ch>'9')
	  w|=ch=='-',ch=getchar();
	while (ch>='0' && ch<='9')
	  X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	return w ? -X : X;
}

inline LL gcd(LL a,LL b){
	return !b ? a : gcd(b,a%b);
}

inline int solve(){
	if (A<B) return 0;
	if (A<C && B>D) return 0;
	if (A<C && B==D) return 1;
	LL res=gcd(B,D),res2=(A-C)/res;
	if (A<C) res2=(A-C+1)/res-1;
	LL res3=A-res*res2;
	if (B>=C){
		if (res3-B+D<B) return 0;
		  else if (res3>=B) return 1;
		    else return 0;
	}
	else{
		if (B<=D) return 1;
		  else if (res3-B+D>=C) return 1;
		    else return 0;
	}
}

int main(){
	T=read();
	while (T--){
		scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
		C++;
		if (solve()) puts("Yes");
		  else puts("No");
	}
	return 0;
}