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

const ll MOD = 998244353;
const ll MAX = 2000001;

ll mod(ll a){
  if(a % MOD < 0) return MOD + (a % MOD);
  return a % MOD;
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}


int main(){
  vl cusum(1000000);
  queue<ll> q; set<ll> prime;
  prime.insert(2);
  
  for(ll i=3; i < 100001; i += 2){
    bool isprime = true;
    
    for(ll j=2; j*j <= i; j++){
      if(i % j == 0){
        isprime = false;
        break;
      }
    }
    
    if(isprime){
      q.push(i);
      prime.insert(i);
    }
  }
  
  while(!q.empty()){
    ll x = q.front();
    
    if(prime.count((x+1)/2)){
      cusum[x]++;
    }
    
    q.pop();
  }
  
  ll now = 0;
  for(ll i=0; i < 1000000; i++){
    if(cusum[i] == 1) now++;
    cusum[i] = now;
  }
  
  ll query; cin >> query;
  
  rep(i,query){
    ll l,r; cin >> r >> l;
    cout << cusum[l] - cusum[r-1] << endl;
  }
  
  /*for(ll i=0; i < 100; i++){
    cout << cusum[i];
  }*/
}