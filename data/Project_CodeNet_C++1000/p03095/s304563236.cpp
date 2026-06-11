#include "bits/stdc++.h"

#define MOD 1000000007
#define rep(i, n) for(ll i=0; i < (n); i++)
#define rrep(i, n) for(ll i=(n)-1; i >=0; i--)
#define ALL(v) v.begin(),v.end()
#define rALL(v) v.rbegin(),v.rend()
#define FOR(i, j, k) for(ll i=j;i<k;i++)
#define DUMP(i, v)for(ll i=0;i<v.size();i++)cerr<<v[i]<<" "

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

struct dijkstra{
  ll N;
  llvec d;
  vector<vector<edge>> e;
  dijkstra(ll n){
    N = n;
    //d = llvec(N, 1e18);
    e = vector<vector<edge>>(N);
  }

  void add_edge(ll from, ll to, ll cost){
    e[from].push_back({to, cost});
  }

  void run(ll start){
    priority_queue<P, vector<P>, greater<P>> que;
    que.push({0, start});
    d = llvec(N, 1e18);
    d[start]=0;
    while(!que.empty()){
      P q = que.top();que.pop();
      ll dc = q.first;
      ll x = q.second;
      if(dc>d[x]){
        continue;
      }else{
        for(auto ip: e[x]){
          if(d[ip.x]<=d[x]+ip.c){
            continue;
          }else{
            d[ip.x]= d[x]+ip.c;
            que.push({d[ip.x], ip.x});
          }
        }
      }
    }
  }
  
};


/**************************************
** A main function starts from here  **
***************************************/
int main(){
  ll N;
  string S;
  cin >> N >> S;
  llvec a(26, 0);
  rep(i, N){
    a[S[i]-'a']++;
  }

  ll ans = 1;
  rep(i, 26){
    ans = mod(ans*(a[i]+1), MOD);
  }
  cout << ans - 1;
  
  return 0;
}
