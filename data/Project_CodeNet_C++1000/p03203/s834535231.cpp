#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int mn[200010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),k=gi(),x,y;
	memset(mn,63,sizeof mn);
	while(k--){
		x=gi(),y=gi();
		mn[x]=std::min(mn[x],y);
	}
	int R=1;
	for(int i=2;i<=n;++i){
		if(mn[i]<=R){
			printf("%d\n",i-1);
			return 0;
		}
		if(mn[i]!=R+1)++R;
	}
	printf("%d\n",n);
	return 0;
}
