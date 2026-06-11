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



int main(){
  ll k,a,b; cin >> k >> a >> b;
  
  if(a+2 >= b) cout << k+1 << endl;
  else if(k <= a) cout << k+1 << endl;
  
  else {
    if((k-a+1) % 2 == 0){
      cout << (k-a+1)/2 * (b-a) + a << endl;
    }
    else{
      cout << (k-a)/2 * (b-a) + a + 1 << endl;
    }
    
  }
  
}