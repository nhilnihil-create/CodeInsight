#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(n) cout << fixed << setprecision(n);
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
  string s; cin >> s;
  ll n = s.size();
  
  if(n == 7){
    if(s == "keyence") cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  
  else{
    for(ll i=0; i < 8; i++){
      string ans = "";
      
      for(ll j=0; j < i; j++){
        ans += s[j];
      }
      for(ll j=0; j < 7-i; j++){
        ans += s[n-(7-i)+j];
      }
      
      if(ans == "keyence"){
        cout << "YES" << endl;
        return 0;
      }
    }
    
    cout << "NO" << endl;
  }
  
}