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
  vvl c(3,vl(3)); vl a(3); vl b(3);
  
  rep(i,3){
    rep(j,3){
      cin >> c[i][j];
    }
  }
 
  
  b[0] = c[0][0];
  b[1] = c[0][1];
  b[2] = c[0][2];
  a[1] = c[1][0] - b[0];
  a[2] = c[2][0] - b[0];
  
  bool flag = true;
  for(ll i=1; i < 3; i++){
    for(ll j=1; j < 3; j++){
      if(a[i] + b[j] != c[i][j]) flag = false;
    }
  }
  
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}