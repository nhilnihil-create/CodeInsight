#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int main() {
  long double n,m,d;
  cin>>n>>m>>d;
  long double ans=(m-1.0)*2*(n-d)/(n*n);
  if(d==0.0) ans/=2.0;
  cout<<fixed<<setprecision(7)<<ans<<endl;
  return 0;
}
