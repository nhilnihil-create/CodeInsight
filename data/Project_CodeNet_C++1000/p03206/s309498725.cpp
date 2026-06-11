#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
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
  ll d; cin >> d;
  
  if(d==25) cout << "Christmas" << endl;
  else if(d==24) cout << "Christmas Eve" << endl;
  else if(d==23) cout << "Christmas Eve Eve" << endl;
  else if(d==22) cout << "Christmas Eve Eve Eve" << endl;
}