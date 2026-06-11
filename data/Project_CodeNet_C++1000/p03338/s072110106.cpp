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
  ll n; string s; cin >> n >> s;
  
  ll maxcommon = 0;
  
  for(ll i=1; i < n; i++){
    
    set<char> first; 
    ll common = 0;
    
    for(ll j=0; j < i; j++){
      first.insert(s[j]);
    }
    for(ll j=i; j < n; j++){
      if(first.count(s[j])){
        common++;
        first.erase(s[j]);
      }
    }
    
    maxcommon = max(maxcommon,common);
    
  }
  
  cout << maxcommon << endl;

  
}