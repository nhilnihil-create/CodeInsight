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
  map<string,ll> point;
  
  ll n; cin >> n;
  
  rep(i,n){
    string s; cin >> s;
    if(point.count(s)){
      point[s]++;
    }
    else{
      point[s] = 1;
    }
  }
  
  ll m; cin >> m;
  
  rep(i,m){
    string s; cin >> s;
    if(point.count(s)){
      point[s]--;
    }
  }
  
  ll maxpoint = 0;
  
  for(auto p : point){
    ll pnt = p.second;
    maxpoint = max(maxpoint,pnt);
  }
  
  cout << maxpoint << endl;
  
}