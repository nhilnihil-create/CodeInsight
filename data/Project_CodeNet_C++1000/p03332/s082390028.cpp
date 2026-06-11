#include <bits/stdc++.h>
using namespace std;

#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define ll long long
#define lop(i,n) for(int i=0;i<n;++i)
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

const int mod=998244353,mN=3e5+100;

inline int add(int a,int b){
   a+=b;
   if(a<0)a+=mod;
   if(a>=mod)a-=mod;
   return a;
}
inline int mul(int a,int b){
   ll ret=1LL*a*b;
   if(ret>=mod)ret%=mod;
   return ret;
}
inline int pwm(int a,ll p){
   int m=a,ret=1;
   while(p){
      if(p&1)ret=mul(ret,m);
      m=mul(m,m);
      p>>=1;
   }
   return ret;
}
int fact[mN];
inline int nCr(int n,int r){
	if(r>n||r<0)return 0;
	return mul( mul( fact[n] , pwm(fact[n-r],mod-2) ) , pwm(fact[r], mod-2 )) ;
}

int n,a,b;
ll k;

int main() {
#ifndef ONLINE_JUDGE
    //freopen("i.txt", "r", stdin);
#endif
    fact[0]=1;
    for(int i=1;i<mN;i++)
    	fact[i]=mul(i,fact[i-1]);
    cin>>n>>a>>b>>k;
    int out = 0;
    for(int r=0;r<=n && 1LL*r*a<=k ;r++){
    	ll rem = k-1LL*r*a;
    	if(rem%b)continue;
    	ll B=rem/b;
    	if(B>n)continue;
    	out =add(out, mul(nCr(n,r),nCr(n,B)) );
    }
    cout<<out<<endl;
}
