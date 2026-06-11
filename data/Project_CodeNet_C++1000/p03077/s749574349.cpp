#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<int, int> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  ll n;
  cin >> n;
  ll x = 100000000000000000;
  rep(i,5){
    ll t;
    cin >> t;
    x = min(x,t);
  }

  if(n%x==0){
    cout << n/x+4 << endl;
  }else{
    cout << n/x+5 << endl;
  }

  return 0;
}