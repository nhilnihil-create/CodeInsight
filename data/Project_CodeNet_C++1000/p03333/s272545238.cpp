#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
ll n,ans,t,l[100005],r[100005];
int main(){
	n=read();
	for(int i=0;i<n;i++)
		l[i]=-read(),r[i]=read();
	sort(l,l+n),sort(r,r+n);
	for(int i=0;i<n;i++)
		ans=min(ans,t+min(min(l[i],r[i]),l[i]+r[i])),t+=l[i]+r[i];
	printf("%lld",-ans*2);
	return 0;
}