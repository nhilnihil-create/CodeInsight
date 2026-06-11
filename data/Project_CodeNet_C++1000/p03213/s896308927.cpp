#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

map<ll,ll> m;

void prime_factor(ll n){
  for(ll i=2;i*i<=n;i++) {
    ll tmp=0;
    while(n%i==0){
      tmp++;
      n/=i;
    }
    if(tmp!=0) m[i]+=tmp;
  }
  if(n!=1) m[n]++;
}

int main() { 
  ll n;
  cin>>n;
  
  for(int i=2;i<=n;i++) prime_factor(i);
  
  int c2=0,c4=0,c14=0,c24=0,c74=0;
  for(auto x:m){
    if(x.second>=2) c2++;
    if(x.second>=4) c4++;
    if(x.second>=14) c14++;
    if(x.second>=24) c24++;
    if(x.second>=74) c74++;
  }
  
  int ans=c74+c24*(c2-1)+c14*(c4-1)+c4*(c4-1)/2*(c2-2);
  cout<<ans<<endl;

  return 0;
}