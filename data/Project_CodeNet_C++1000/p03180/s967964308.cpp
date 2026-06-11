#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(int x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { int d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

vector<ll> dp;
vector<vector<ll>> a;
int N;

ll dfs(ll n) {
  if (dp[n]!=-1) return dp[n];
  ll result = 0, sum = 0;
  rep(i,N) repr(j,i+1,N) if (n&(1<<i)&&n&(1<<j)) sum += a[i][j];
  result = max(result, sum);
  for (int i=(n-1)&n; i>0; i=(i-1)&n) result = max(result, dfs(i)+dfs(n^i));
  return dp[n] = result;
}

int main() {
  cin >> N;
  a.resize(N, vector<ll>(N)); rep(i,N) rep(j,N) cin >> a[i][j];
  dp.resize(1<<N,-1);
  ll result = dfs((1<<N)-1);
  cout << result << endl;
  // debug(all(dp));
  return 0;
}