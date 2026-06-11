#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (ll i=(ll)from; i<(ll)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (ll i=(ll)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const ll INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(ll x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { ll d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll modpow(ll x, ll p) { ll result = 1, now = 1, pm = x; while (now<=p) { if (p&now) { result = result * pm % MOD; } now*=2; pm = pm*pm % MOD; } return result; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

vector<vector<ll>> adj;

void c_dis(vector<int> &d, int n=0, int p=-1) {
  if (p==-1) d[n] = 0;
  for (auto x: adj[n]) {
    if (x==p) continue;
    d[x] = d[n]+1;
    c_dis(d,x,n);
  }
}

void dfs(vector<ll> &dis, ll n=0, ll p=-1) {
  for (auto x: adj[n]) {
    if (x==p||dis[x]!=-1) continue;
    dis[x] = dis[n]+1;
    dfs(dis,x,n);
  }
}

ll calc_d() {
  int N = adj.size();
  vector<int> d_0(N,-1); c_dis(d_0,0,-1);
  int d0_pos = 0; rep(i,N) if (d_0[d0_pos]<d_0[i]) d0_pos = i;
  vector<int> d_1(N,-1); c_dis(d_1,d0_pos,-1);
  int d1_pos = 0; rep(i,N) if (d_1[d1_pos]<d_1[i]) d1_pos = i;
  return d_1[d1_pos];
}


int main() {
  ll N; cin >> N;
  adj.resize(N);
  rep(i,N-1) {
    ll a, b; cin >> a >> b; a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  ll d = calc_d();
  string result = d%3!=1 ? "First" : "Second";
  cout << result << endl;
  return 0;
}