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

vector<P> p;
ll N, M;

P root(ll a){
  ll atmp = a;
  ll cnt = 0;
  while(atmp!=p[atmp].second){
    atmp = p[atmp].second;
    cnt++;
  }
  p[a].second = atmp;
  return P(cnt, atmp);
}

void con(ll a, ll b){
  P tmpa = root(a);
  P tmpb = root(b);
  if(tmpa.first>tmpb.second){
    swap(tmpa, tmpb);
  }
  p[tmpa.second].second = tmpb.second;
}

/**************************************
** A main function starts from here  **
***************************************/
int main(){
  cin >> N >> M;
  p.resize(N);
  rep(i, N){
    cin >> p[i].first;
    p[i].first--;
    p[i].second = i;
  }

  rep(i, M){
    ll a, b;
    cin >> a >> b;
    a--;b--;
    con(a, b);
  }
  
  map<ll, set<ll>> mp;
  rep(i, N){
    P piroot=root(p[i].second);
    mp[piroot.second].insert(i);
  }
  
  ll ans = 0;
  rep(i, N){
    P piroot=root(p[i].second);
    if(mp[piroot.second].count(p[i].first)>0)ans++;
  }
  cout << ans;
  return 0;
}
