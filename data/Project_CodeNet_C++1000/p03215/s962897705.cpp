#include "bits/stdc++.h"

#define MOD 1000000007
#define rep(i, n) for(ll i=0; i < (n); i++)
#define rrep(i, n) for(ll i=(n)-1; i >=0; i--)
#define ALL(v) v.begin(),v.end()
#define rALL(v) v.rbegin(),v.rend()
#define FOR(i, j, k) for(ll i=j;i<k;i++)
#define debug_print(var) cerr << #var << "=" << var <<endl;
#define DUMP(i, v)for(ll i=0;i<v.size();i++)cerr<<v[i]<<" "
#define fi first
#define se second

using namespace std;
typedef long long int ll;
typedef vector<ll> llvec;
typedef vector<double> dvec;
typedef pair<ll, ll> P;
typedef long double ld;
struct edge{ll x, c;};

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
  ll b=mod, u=1, v=0;
  while(b){
    ll t=a/b;
    a-=t*b; swap(a, b);
    u-=t*v; swap(u, v);
  }
  u%=mod;
  if(u<0)u+=mod;
  return u;
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
/**************************************
** A main function starts from here  **
***************************************/
int main(){
  ll N, K;
  cin >> N >> K;
  llvec a(N), S(N+1, 0);
  rep(i, N){
    cin >> a[i];
    S[i+1] = S[i] + a[i];
  }

  llvec d(50, 0);
  llvec A;
  for(ll i=0;i<=N;i++){
    for(ll j=i+1;j<=N;j++){
      ll t= S[j]-S[i];
      rep(k, 50){
        if(t>>k&1)d[k]++;
      }
      A.push_back(t);
    }
  }

  llvec tmp = A;
  for(ll i=49;i>=0;i--){
    if(d[i]>=K){
      llvec tmp2;
      llvec d2(50, 0);
      for(auto itmp:tmp){
        if(itmp>>i&1){
          tmp2.push_back(itmp);
          rep(k, i){
            if(itmp>>k&1){
              d2[k]++;
            }
          }
        }
      }
      d=d2;
      tmp=tmp2;
    }
    //cerr << i << " ";DUMP(s, tmp);cerr << endl;
    if(tmp.size()==K){
      break;
    }
  }
  ll ans =tmp[0];
  rep(i, K){
    ans = ans & tmp[i];
  }

  cout << ans<< endl;
  
  return 0;
}
