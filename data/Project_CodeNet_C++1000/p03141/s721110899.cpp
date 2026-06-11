#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  int n;
  cin >> n;
  vector<ll> ab(n);
  ll bmax=0;
  for(int i=0;i<n;++i){
    ll a,b;
    cin >> a >> b;
    ab[i]=a+b;
    bmax+=b;
  }
  sort(ab.rbegin(),ab.rend());
  ll ans=0;
  for(int i=0;i<n;++i){
    if(i%2==0) ans+=ab[i];
  }
  ans-=bmax;
  cout << ans << endl;
  return 0;
}
