#include <bits/stdc++.h>
#include <stdlib.h>
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
  string s;
  int k;
  cin>>s>>k;
  set<string> memo;
  int l=s.size();
  for(int i=1;i<=min(l,5);i++){
    for(int j=0;j<=l-i;j++){
      memo.insert(s.substr(j,i));
    }
  }
  auto itr=memo.begin();
  for(int i=0;i<k-1;i++) itr++;
  cout<<*itr<<endl;
  return 0;
}

