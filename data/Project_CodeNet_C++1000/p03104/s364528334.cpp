#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

ll q(ll n){
  if(n%4==1) return 1;
  if(n%4==2) return n+1;
  if(n%4==3) return 0;
  if(n%4==0) return n;
}

int main(){
  ll a,b;
  cin>>a>>b;
  ll ra,rb;
  ra=q(a-1);
  rb=q(b);
  ll ans;
  if(a==0) ans=rb;
  else ans=rb^ra;
  cout<<ans<<endl;
}