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

const ll MOD = 1000000007;
const ll MAX = 2000001;

ll mod(ll a){
  return a % MOD;
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}


int main(){
  ll a,b; cin >> a >> b;
  
  ll pera = a % 4;
  ll perb = (b+1) % 4;
  
  if(pera == 0) a = 0;
  else if(pera == 1) a--;
  else if(pera == 2) a = 1;
  
  if(perb == 0) b = 0;
  else if(perb == 2) b = 1;
  else if(perb == 3) b++;
  
  cout << (a^b) << endl;
  
  
}