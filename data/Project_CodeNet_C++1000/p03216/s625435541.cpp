#include<bits/stdc++.h>
const int N=1e6+5;
int n,a[N],i,Q,k,q[N],t,w;
char s[N];
long long ans,z;
int main(){
	scanf("%d%s%d",&n,s+1,&Q);for(i=1;i<=n;++i)a[i]=a[i-1]+(s[i]=='M');
	for(;Q--;){
		scanf("%d",&k);
		t=1;w=z=ans=0;
		for(i=1;i<=n;++i){
			for(;t<=w && i-q[t]>=k;z-=a[q[t++]]);
			if(s[i]=='C')ans+=1ll*a[i]*(w-t+1)-z;
			if(s[i]=='D')z+=a[q[++w]=i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}