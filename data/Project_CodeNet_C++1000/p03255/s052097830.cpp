#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<ctime>
#define MAXN 200005
#define ll long long
#define maxn 15
#define maxs 1000005
#define inf (9e18)
#define eps 1e-9
using namespace std;
inline char gc() {
	static char now[1<<16],*S,*T;
	if (T==S) {
		T=(S=now)+fread(now,1,1<<16,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
inline ll readlong() {
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return x*f;
}
void putint(long long t) {
	int ans[40]= {0};
	for(; t; t/=10)ans[++ans[0]]=t%10;
	for(; ans[0]; ans[0]--)putchar('0'+ans[ans[0]]);
	putchar('\n');
}
const int N=200005;
ll x;
int n;
ll ans=inf;
ll a[N];
int main(){
	n=read();
	x=readlong();
	for(int i=1;i<=n;i++){
		a[i]=readlong();
		a[i]+=a[i-1];
	}
	for(int k=1;k<=n;k++){
		ll num_xi=3ll;
		ll sum=0;
		for(int i=n;i>=1;i-=k){
			sum+=(a[i]-a[max(0,i-k)])*max(num_xi,5ll);
			num_xi+=2;
			if(sum>=ans){
				break;//防爆 
			}
		}
		ans=min(ans,sum+(ll)(k+n)*x);
	}
	printf("%lld\n",ans);
	return 0;
}
