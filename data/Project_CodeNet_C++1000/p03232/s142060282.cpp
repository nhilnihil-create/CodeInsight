#include<bits/stdc++.h>
using namespace std;
const int p=1000000007,N=100005;
int n,i,a[N];
long long frac[N],inv[N],invf[N],invs[N],fst[N],ans[N],Ans;
int main(){
  scanf("%d",&n);
  for(i=1;i<=n;++i)scanf("%d",&a[i]);
  frac[0]=1;
  for(i=1;i<=n;++i)frac[i]=frac[i-1]*i%p;
  inv[1]=invf[1]=1;
  for(i=2;i<=n;++i){
    inv[i]=(-(p/i)*inv[p%i]%p+p)%p;
    invs[i]=(invs[i-1]+inv[i])%p;
    invf[i]=invf[i-1]*inv[i]%p;
  }
  fst[1]=1;
  for(i=2;i<=n;++i)fst[i]=(fst[i-1]*i+frac[i-1])%p;
  //for(i=1;i<=n;++i)printf("fst[%d] = %lld\n",i,fst[i]);
  for(i=1;i<=n;++i)ans[i]=(fst[i]*invf[i]+invs[n-i+1])%p*frac[n]%p;
  for(i=1;i<=n;++i)Ans=(Ans+ans[i]*a[i])%p;
  //for(i=1;i<=n;++i)printf("ans[%d] = %lld\n",i,ans[i]);
  printf("%lld",Ans);
}
