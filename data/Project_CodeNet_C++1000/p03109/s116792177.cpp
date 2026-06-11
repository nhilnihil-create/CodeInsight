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
  if(s[6] == '3' || s[6] == '4' ||
     (s[5] == '0' && s[6] == '1') ||
     (s[5] == '0' && s[6] == '2'))
    cout << "Heisei" << endl;
  else cout << "TBD" << endl;
}