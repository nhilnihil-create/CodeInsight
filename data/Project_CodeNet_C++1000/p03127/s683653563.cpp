#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  int n;
  cin >> n;

  vector<ll> a(n);
  rep(i,n) cin >> a.at(i);

  ll ans=a.at(0);
  rep(i,n) ans = gcd(ans,a.at(i));

  cout << ans;
}