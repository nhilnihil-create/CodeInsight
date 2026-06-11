#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,h;
  cin >> n >> h;
  vector<ll> a(n),b(n);
  ll maxi=0,maxi_b;
  rep(i,n){
    cin >> a.at(i) >> b.at(i);
    if(maxi<a.at(i)){
      maxi=a.at(i);
      maxi_b=b.at(i);
    }
  }
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  ll is=0,ans=0;
  for(ll i=0;i<n;i++){
    if(b.at(i)<=maxi){
      break;
    }
    is+=b.at(i);
    ans++;
    if(is>=h){
      cout << ans << endl;
      return 0;
    }
  }
  ans+=(h-is+maxi-1)/maxi;
  cout <<ans;
}
           
