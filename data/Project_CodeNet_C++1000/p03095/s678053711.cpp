#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
ll l=1000000007;
string alphabet="abcdefghijklmnopqrstuvwxyz";

int main() {
  ll n; cin>>n;
  string s; cin>>s;
  vector<ll> v(26,0);
  rep(i,n){
    rep(j,26){
      if(s[i]==alphabet[j]){v[j]++;}
    }
  }
  ll ans=1;
  /*for (ll tmp = 1; tmp < (1 << 5); tmp++) {
    bitset<5> b(tmp);//cout<<b<<endl;
    ll x=1;
    rep(i,5){ if(b.test(i)){x*=v[i]; x%=l;} }//cout<<x;
    ans+=x; ans%= l;
  }*/
  rep(i,26){
    ans*=v[i]+1; ans%=l;
  }
  ans--;
  cout<<ans;
}