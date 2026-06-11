//Wrong answer on test inf.
#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
#define inf 1000000001
#define y1 y1___
using namespace std;
char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
ll read(){
	char ch=gc();ll x=0;int op=1;
	for (;!isdigit(ch);ch=gc()) if (ch=='-') op=-1;
	for (;isdigit(ch);ch=gc()) x=(x<<1)+(x<<3)+ch-'0';
	return x*op;
}
ll n,now;
double cal(ll x){
	ll y=x,ret=0;
	while (x) ret+=x%10,x/=10;
	return 1.*y/ret;
}
bool ok(ll x){
	ll t=1;
	while (t<=x){
		if (cal(x+t)<cal(x)) return 0;
		t*=10;
	}
	return 1;
}
int main(){
	n=read();
	while (n--){
		ll t=1;
		while (1)
			if (ok(now+t)){now+=t;break;}
			else t*=10;
		printf("%lld\n",now);
	}
	return 0;
}