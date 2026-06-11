#include<cstdio>
#include<cstring>
const int N=1<<20;
typedef long long ll;
int n;
char c[N];
int q;
int K[80];
int pD[N],pM[N],pC[N];
ll Mul[N];
void precalc(){
    for(int i=0;i<n;++i){
        pD[i+1]=pD[i];
        pM[i+1]=pM[i];
        pC[i+1]=pC[i];
        Mul[i+1]=Mul[i];
        if(c[i]=='D')++pD[i+1];
        if(c[i]=='M')++pM[i+1];
        if(c[i]=='C'){
            ++pC[i+1];
            Mul[i+1]+=pM[i];
        }
    }
}
ll ans[80];
int main(){
    scanf("%d%s%d",&n,c,&q);
    for(int i=0;i<q;++i)scanf("%d",&K[i]);
    precalc();
    for(int a=0;a<n;++a)if(c[a]=='D'){
        for(int i=0;i<q;++i){
            int mxc=a+K[i];
            if(mxc>n)mxc=n;
            ans[i]+=Mul[mxc]-Mul[a];
            ans[i]-=1LL*(pC[mxc]-pC[a])*pM[a];
        }
    }
    for(int i=0;i<q;++i)printf("%lld\n",ans[i]);
    return 0;
}