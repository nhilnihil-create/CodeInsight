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

ll gcd(ll a, ll b){
  ll r = a%b;
  if(r==0) return b;
  else return gcd(b, a%b);
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

vector<char> v;


/**************************************
** A main function starts from here  **
***************************************/
int main(){
  string S;
  int K;
  cin >> S;
  cin >> K;
  ll N = S.size();  

  set<string> C;
  rep(i, N){
    for(int len=1;len<=min(5LL, N-i);len++){
      C.insert(S.substr(i, len));
    }
  }

  auto iter = C.begin();
  rep(i, K-1){
    //cout<<*iter<<endl;
    iter++;
  }

  cout << *iter;
  
  /*
  for(int len=1;len<=5;len++){
    if(N-len<0)break;
    rep(i, N-len){
      C[len-1].insert(S.substr(i,len));
    }
  }
  rep(i, 5){
    cout << i << " " << C[i].size() << endl;
    if(C[i].size()>K){
      auto iter = C[i].begin();
      rep(i, K-1){
        iter++;
        cout << *iter;
        return 0;
      }
    }else{
      K = K-C[i].size();
    }
    }
*/
  
  return 0;
}
