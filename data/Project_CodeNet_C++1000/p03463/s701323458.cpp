#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll> 
#define P pair<ll,ll>
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,a,b;cin>>n>>a>>b;
  string win;
  if((b-a-1)%2==1) win="Alice"; else win="Borys";
  print(win);
  return 0;
}