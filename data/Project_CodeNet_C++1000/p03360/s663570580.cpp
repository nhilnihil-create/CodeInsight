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
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  int M=max({a,b,c});
  int sum=a+b+c-M;
  for(int i=0;i<k;i++){
    M*=2;
  }
  cout<<M+sum<<endl;
  return 0;
}
