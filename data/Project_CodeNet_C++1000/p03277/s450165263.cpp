#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=100005;
int tong[N<<1],a[N],n,k;
ll check(int x){
	memset(tong,0,sizeof(tong));
	int dq=n,dd=1; ll ans=0;
	tong[n]=1; 
	for(register int i=1;i<=n;i++){
		a[i]>=x?dd+=tong[++dq]:dd-=tong[dq--]; 
		ans+=dd++; tong[dq]++; 
	}
	return ans;
}
signed main(){
	n=read(); ll k=((ll)n*(n+1)/2+1)/2;
	for(int i=1;i<=n;i++)a[i]=read(); 
	int l=1,r=1e9;
	while(l<r){
		int mid=(l+r)>>1; mid++;
		if(check(mid)>=k)l=mid; else r=mid-1;
	}
	cout<<l<<endl;
}