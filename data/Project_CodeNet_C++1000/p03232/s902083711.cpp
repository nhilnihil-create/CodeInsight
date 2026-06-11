#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iomanip>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<list>
#include<deque>
#include<bitset>
#include<fstream>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair<int,int >
#define iiii pair<int,pii >
#define mp make_pair
#define INF 1000000000
#define MOD 1000000007
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
    int x=0,p=1;char c=getchar();
    while (c<=32)c=getchar();
    if(c==45)p=-p,c=getchar();
    while (c>32)x=x*10+c-48,c=getchar();
    return x*p;
}
using namespace std;
//ruogu
const int N=1e5+10;
int n,p[N],res;
//
inline void add(int &x,int y){
	x+=y;
	if(x>=MOD)x-=MOD;
}
inline int mul(int x,int y){
	ll ans=1ll*x*y;
	return ans%MOD;
}
inline int modpow(int x,int y){
	int ans=1;
	while(y>0){
		if(y&1)ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
inline int modinv(int x){
	return modpow(x,MOD-2);
}
int main(){
	n=getint();
	for(int i=1;i<=n;i++){
		add(p[i],p[i-1]);
		add(p[i],modinv(i+1));
	}
	rep(i,n){
		int x=getint();
		add(res,mul(p[i],x));
		add(res,x);
		add(res,mul(p[n-i-1],x));
	}
	rep(i,n)res=mul(res,i+1);
	printf("%d\n",res);
	return 0;
}