//#define _GLIBCXX_DEBUG
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
  if(a % MOD < 0) return MOD + (a % MOD);
  else return a % MOD;
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}


int main(){
  ll x,y,z,k; cin >> x >> y >> z >> k;
  
  vl cakex(x); vl cakey(y); vl cakez(z);
  
  rep(i,x) cin >> cakex[i];
  rep(i,y) cin >> cakey[i];
  rep(i,z) cin >> cakez[i];
  
  vl waitxy(max(x*y,k),0LL);
  
  //for(ll a : waitxy) cout << a << endl;
  
  for(ll i=0; i < x; i++){
    for(ll j=0; j < y; j++){
      waitxy[y*i + j] = cakex[i] + cakey[j];
    }
  }
  
  sort(all(waitxy)); reverse(all(waitxy));
  vl waitall(k*z,0LL);
  
  
  
  for(ll i=0; i < k; i++){
    for(ll j=0; j < z; j++){
      waitall[i*z + j] = cakez[j] + waitxy[i];
      //cout << waitxy[i] << ' ' << cakez[j] << ' ' << waitall[i*z + j] << endl;
    }
  }

  
  //for(ll a : cakez) cout << a << endl;
  
  
  sort(all(waitall)); reverse(all(waitall));
  
  rep(i,k){
    cout << waitall[i] << endl;
  }
  
  
}