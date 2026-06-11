#include "bits/stdc++.h"

#define MOD 1000000007
#define rep(i, n) for(ll i=0; i < (n); i++)
#define ALL(v) v.begin(),v.end()

using namespace std;
typedef long long int ll;
typedef vector<ll> llvec;
typedef vector<double> dvec;
typedef pair<int, int> P;


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

int N;
int M;
vector<llvec> est;


ll sumv(int flag, llvec a){
  if(flag == 0) return a[0] + a[1] + a[2];
  if(flag == 1) return -a[0] + a[1] + a[2];
  if(flag == 2) return a[0] - a[1] + a[2];
  if(flag == 3) return a[0] + a[1] - a[2];
  if(flag == 4) return a[0] - a[1] - a[2];
  if(flag == 5) return -a[0] + a[1] - a[2];
  if(flag == 6) return -a[0] - a[1] + a[2];
  if(flag == 7) return -a[0] - a[1] - a[2];
}

/******************************************
** A main function is start from here  ****
*******************************************/
int main(){
  cin >> N >> M;
  rep(i, N){
    llvec tmp;
    ll tmp2;
    cin >> tmp2;
    tmp.push_back(tmp2);
    cin >> tmp2;
    tmp.push_back(tmp2);
    cin >> tmp2;
    tmp.push_back(tmp2);
    est.push_back(tmp);
  }
  ll ans = 0;
  rep(f, 8){
    sort(ALL(est), [f](llvec a, llvec b){return sumv(f, a)>sumv(f, b);});
    ll cand = 0;
    rep(i, M){
      cand += sumv(f, est[i]);
    }
    ans = max(ans, cand);
  }
  cout << ans;
  return 0;
}
