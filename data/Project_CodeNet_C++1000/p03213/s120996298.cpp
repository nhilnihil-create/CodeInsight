#include "bits/stdc++.h"

#define MOD 1000000007
#define rep(i, n) for(ll i=0; i < (n); i++)
#define ALL(v) v.begin(),v.end()
#define DUMP(i, v)for(ll i=0;i<v.size();i++)cout<<v[i]<<" "

using namespace std;
typedef long long int ll;
typedef vector<ll> llvec;
typedef vector<double> dvec;
typedef pair<int, int> P;
struct Edge{ll from, to, cost;};

ll mod(ll a, ll mod){
  ll res = a%mod;
  if(res<0)res=res + mod;
  return res;
}

ll modpow(ll a, ll n, ll mod){
  ll res=1;
  while(n>0){
    if(n&1) res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll modinv(ll a, ll mod){
  return modpow(a, mod-2, mod);
}

bool is_prime(ll n){
  ll i = 2;
  if(n==1)return false;
  if(n==2)return true;
  bool res = true;
  while(i*i <n){
    if(n%i==0){
      res = false;
    }
    i = i+1;
  }

  //if(i==1)res = false;
  if(n%i==0)res=false;
  return res;
}


/**************************************
** A main function starts from here  **
***************************************/
int main(){
  ll N;
  set<ll> prime;
  cin >> N;
  rep(i, 101){
    if(is_prime(i+1))prime.insert(i+1);
  }
  map<ll, ll> fact;
  for(auto i: prime){
    ll cnt = 1;
    while(N/pow(i, cnt)>0){
      fact[i]+=N/pow(i, cnt);
      cnt +=1;
    }
  }
  ll ans = 0;
  ll cnt74=0, cnt24=0, cnt14=0, cnt4=0, cnt2=0;
  
  for(auto i:fact){
    //cout << i.first <<" " << i.second << endl;
    if(i.second>=74)cnt74++;
    if(i.second>=24)cnt24++;
    if(i.second>=14)cnt14++;
    if(i.second>=4)cnt4++;
    if(i.second>=2)cnt2++;
  }
  
  ans += cnt74;
  ans += cnt24*(cnt2-1);
  ans += cnt14*(cnt4-1);
  ans += (cnt4-1)*cnt4/2 *(cnt2-2);

  cout << ans;
  return 0;
}
