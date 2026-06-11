#include<bits/stdc++.h>
#define FIO "agc31B"
#define ll long long

const int N=2e5+5,MOD=1e9+7;

inline int add(int a,const int &b){a+=b;return a>=MOD?a-MOD:a;}
inline int sub(int a,const int &b){a-=b;return a<   0?a+MOD:a;}
inline int mul(const int &a,const int &b){return 1ll*a*b%MOD;}
inline int& inc(int &a,const int &b){return a=add(a,b);}
inline int& dec(int &a,const int &b){return a=sub(a,b);}
inline int& pro(int &a,const int &b){return a=mul(a,b);}
inline int qpow(int a,int b){int c=1;for(;b;b>>=1,pro(a,a))if(b&1)pro(c,a);return c;}

int n,a[N],f[N],lst[N];

int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  for(int i=1;i<=n;i++)lst[a[i]]=n+1;
  f[0]=1;
  for(int i=1;i<=n;i++){
    f[i]=add(f[i-1],a[i]==a[i-1]?0:f[lst[a[i]]]);
    lst[a[i]]=i;
  }
  printf("%d\n",f[n]);
  return 0;
}
