#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll a,ll b){
  ll ans;
  while(b>0){
    ll r=a%b;
    a=b;
    b=r;
  }
  return a;
}
int main(){
  ll n,x;
  cin >> n >> x;
  vector<ll> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  vector<ll> p(n);
  rep(i,n){
    p.at(i)=abs(a.at(i)-x);
  }
  ll maxi=p.at(0);
  rep(i,n-1){
    maxi=gcd(maxi,p.at(i+1));
  }
  cout << maxi;
  
}