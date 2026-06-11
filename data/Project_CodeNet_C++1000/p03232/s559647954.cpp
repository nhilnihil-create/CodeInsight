#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mod=1e9+7;

int n,ans,nv[N],ss[N],frac;

inline int ad(int x,int y){x+=y;return x>=mod?x-mod:x;}
inline int dc(int x,int y){x-=y;return x<0?x+mod:x;}
inline int mul(int x,int y){return 1ll*x*y%mod;}

int main(){
	int i,j,x;
	scanf("%d",&n);
    nv[0]=nv[1]=ss[1]=frac=1;
    for(i=2;i<=n;++i){
    	nv[i]=mul(mod-mod/i,nv[mod%i]);
    	ss[i]=ad(ss[i-1],nv[i]);
    	frac=mul(i,frac);
    }
    for(i=1;i<=n;++i){
    	scanf("%d",&x);
    	ans=ad(ans,mul(x,ad(ss[i],dc(ss[n-i+1],1))));
    }
    printf("%d\n",mul(frac,ans));
    return 0;
}