#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;

ll factorial[1000001];
ll factorialinv[1000001];
ll calc(ll a,ll b,ll c){
  if(b==0)return 1;
  else if(b%2==0){
    ll d=calc(a,b/2,c);
    return d*d%c;
  }
  else {
    return a*calc(a,b-1,c)%c;
  }
}

int main(){
  ll n,a,b,k,count=0;
  cin >> n >> a >> b >> k;

  factorial[0]=1;
  factorialinv[0]=1;
  for(ll i=1;i<=n;i++){
    factorial[i]=factorial[i-1]*i%mod;
    factorialinv[i]=factorialinv[i-1]*calc(i,mod-2,mod)%mod;
  }
  for (ll i=0;i<=n;i++){
    ll j=(k-a*i)/b;
    if(j>n)continue;
    if (j>=0 && a*i+b*j==k) {
      long long int alpha=1,beta=1;
      alpha=factorial[n]*factorialinv[i]%mod*factorialinv[n-i]%mod;
      beta=factorial[n]*factorialinv[j]%mod*factorialinv[n-j]%mod;
      count=(count+alpha*beta%mod)%mod;
  }
}
cout << count << endl;
}