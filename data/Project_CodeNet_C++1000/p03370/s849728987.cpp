#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<algorithm>//next_permutation
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(n) cout << fixed << setprecision(n);
#define large "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define small "abcdefghijklmnopqrstuvwxyz"
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

ll mod(ll a){
  return (a % 1000000007);
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}

ll nCr(ll n,ll r){
  if(r == 1) return n;
  else if(r == 0) return 1;
  else return nCr(n-1,r-1)*n/r;
}

int main(){
  ll n,x; cin >> n >> x; ll ans = n;
  vl powder(n);
  
  rep(i,n){
    cin >> powder[i];
    x -= powder[i];
  }
  
  sort(all(powder));
  
  while(x >= powder[0]){
    x -= powder[0];
    n++;
  }
  
  cout << n << endl;
  
}