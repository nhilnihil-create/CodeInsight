#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n),b(200001,0);
  rep(i,n){
    cin >> a.at(i);
    b.at(a.at(i))++;
  }
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  ll ans=0;
  rep(i,k){
    ans+=b.at(i);
  }
  cout << n-ans;
}
  
  
                