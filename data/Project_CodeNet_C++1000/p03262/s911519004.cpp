#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

int main(){
  ll n, x;
  cin >> n >> x;

  vector<ll> city(n);
  rep(i,n){
    cin >> city.at(i);
    city.at(i)-=x;
    if(city.at(i)<0) city.at(i)*=-1;
  }

  ll ans=city.at(0);
  rep(i,n){
    if(city.at(i)!=0) ans = gcd(ans, city.at(i));
  }

  cout << ans;
}