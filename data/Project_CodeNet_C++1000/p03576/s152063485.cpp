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

struct UnionFind{
  ll N;
  llvec p;
  llvec cnt;
  UnionFind(ll n){
    N = n;
    p=llvec(N);
    cnt=llvec(N, 0);
    rep(i, N){
      p[i] = i;
      cnt[i] = 1;
    }
  }

  void con(ll a, ll b){
    P at = root(a);
    P bt = root(b);
    if(at.second!=bt.second){
      if(at.first>bt.first){
        swap(at, bt);
        swap(a, b);
      }
      p[at.second] = bt.second;
      cnt[bt.second]+=cnt[at.second];
      p[a]=bt.second;
    }
  }

  P root(ll a){
    ll atmp = a;
    ll c=0;
    while(atmp!=p[atmp]){
      atmp = p[atmp];
      c++;
    }
    p[a] = atmp;
    return {c, atmp};
  }

  bool is_con(ll a, ll b){
    P at=root(a);
    P bt=root(b);
    return at.second == bt.second;
  }
  
};

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
  ll N, K;
  cin >> N >> K;
  vector<P> p(N);
  llvec x, y;
  rep(i, N){
    cin >> p[i].fi >> p[i].se;
    x.push_back(p[i].fi);
    y.push_back(p[i].se);
  }
  sort(ALL(x));
  sort(ALL(y));
  x.erase(unique(ALL(x)), x.end());
  y.erase(unique(ALL(y)), y.end());
  ll nx = x.size();
  ll ny = y.size();
  vector<llvec> m(nx, llvec(ny, 0));
  rep(i, N){
    ll ix = lower_bound(ALL(x), p[i].fi) - x.begin();
    ll iy = lower_bound(ALL(y), p[i].se) - y.begin();
    m[ix][iy]++;
  }
  
  vector<llvec> S(nx+1, llvec(ny+1, 0));
  rep(i, nx){
    rep(j, ny){
      S[i+1][j+1]=S[i+1][j]+S[i][j+1]-S[i][j]+m[i][j];
    }
  }
  /*
  cerr << "  0 ";DUMP(k, y);cerr<<endl;
  rep(i, ny+1){
    cerr << x[i]<<" ";DUMP(k, S[i]);cerr<<endl;    
  }
  */
  x.insert(x.begin(), -1e18);
  y.insert(y.begin(), -1e18);
  ll ans = 5e18;
  rep(i, nx){
    rep(j, ny){
      ll tmp=5e18;
      for(ll ii=i+2; ii<=nx; ii++){
        for(ll jj=j+2; jj<=ny; jj++){
          if(S[ii][jj] -S[ii][j] - S[i][jj]+ S[i][j]>=K){
            tmp = min(tmp, (x[ii]-x[i+1])*(y[jj]-y[j+1]));
          }
        }
      }
      ans = min(ans, tmp);
    }
  }
  cout << ans;
  return 0;
}
