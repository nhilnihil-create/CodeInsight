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

vector<P> c;


/**************************************
** A main function starts from here  **
***************************************/
int main(){
  ll N;
  cin >> N;
  vector<llvec> v(N);
  rep(i, N-1){
    ll a, b;
    cin >> a >> b;
    a--;b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  ll ans = 0;
  rep(i, N){
    ll c1;cin>>c1;
    c.push_back({c1,i});
    ans += c1;
  }
  sort(ALL(c), [](P a, P b){return a.first>b.first;});
  ans -=c[0].first;
  vector<ll> marked(N, 0);
  cout << ans << endl;
  ll ind=1, queind=1;
  queue<ll> que;
  que.push(0);
  marked[0]=1;
  c[0].second=1;
  while(!que.empty()){
    ll current = que.front();
    rep(i, v[current].size()){
      ll next = v[current][i];
      if(marked[next]!=0){
        continue;
      }
      marked[next] = 1;
      c[ind].second=next+1;
      ind++;
      que.push(next);
    }
    que.pop();
  }
  
  sort(ALL(c), [](P a, P b){return a.second<b.second;});
  rep(i, N){
    cout << c[i].first << " " ;
  }
  
  return 0;
}
