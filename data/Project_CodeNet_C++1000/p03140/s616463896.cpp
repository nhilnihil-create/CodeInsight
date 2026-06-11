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
  string a,b,c; ll n; cin >> n >> a >> b >> c; ll cnt = 0;
  
  rep(i,n){
    if(a[i] != b[i] && b[i] != c[i] && c[i] != a[i]) cnt += 2;
    else if(a[i] == b[i] && b[i] == c[i]) cnt += 0;
    else cnt++;
  }
  
  cout << cnt << endl;
  
}