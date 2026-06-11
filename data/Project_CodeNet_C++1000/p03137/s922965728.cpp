#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,m;
  cin >> n >> m;
  vector<ll> a(m),b(m-1);
  rep(i,m){
    cin >> a.at(i);
  }
  sort(a.begin(),a.end());
  ll ans=0;
  rep(i,m-1){
    b.at(i)=abs(a.at(i)-a.at(i+1));
  }
  sort(b.begin(),b.end());
  for(ll i=0;i<m-n;i++){
    ans+=b.at(i);
  }
  cout << ans;
}
