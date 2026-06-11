#include <iostream>
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_r(i, n) for (int i = n - 1; i >= 0; i--)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define BIT(x) 1LL << (x)
#define SZ(x) ((ll)(x).size())
#define bit(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

#ifdef DEBUG
#define OUT(x) std::cout << (x) << std::endl
#define OUT2(x, y) std::cout << (x) << "," << (y) << std::endl
#define OUT3(x, y, z) std::cout << (x) << "," << (y) << "," << (z) << std::endl
#define OUTSP(x) std::cout << (x) << " ";
#define OUTLF std::cout << std::endl
#define OUTPA(p) OUT2(p.first, p.second)
#else
#define OUT(x) NULL
#define OUT2(x, y) NULL
#define OUT3(x, y, z) NULL
#define OUTPA(p) NULL
#define OUTSP(p) NULL
#define OUTLF NULL
#endif

#define INF INT_MAX
#define INFLL LLONG_MAX
#define PB push_back
#define MOD 1000000007LL

#define LSB(x) __builtin_ctzll(x)
#define MSB(x) 64LL - __builtin_clzll(x) - 1LL
#define MSBINT(x) 32LL - __builtin_clz(x)
#define BITCNT(x) __builtin_popcountll(x)

#define pb push_back
#define mod 1000000007

template <class T>
bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
  if (b < a)
  {
    a = b;
    return 1;
  }
  return 0;
}

using namespace std;
using uif = uint_fast64_t;
using ll = long long int;
using tTree = __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using vec = vector<ll>;

int qp(int a, ll b)
{
  int ans = 1;
  do
  {
    if (b & 1)
      ans = 1ll * ans * a % mod;
    a = 1ll * a * a % mod;
  } while (b >>= 1);
  return ans;
}
int qp(int a, ll b, int mo)
{
  int ans = 1;
  do
  {
    if (b & 1)
      ans = 1ll * ans * a % mo;
    a = 1ll * a * a % mo;
  } while (b >>= 1);
  return ans;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define FACSIZE 2002

ll invfac[FACSIZE];
ll fac[FACSIZE];

ll mod_pow(ll, ll);
ll mod_add(ll, ll);
ll mod_mul(ll, ll);
ll mod_div(ll, ll);
void make_fact(ll);
void make_invfact(ll);

ll powLL(ll x, ll y)
{
  ll ans = 1;
  for (ll i = 0; i < y; i++)
    ans *= x;
  return ans;
}

using ma = map<pair<string, string>, ll>;

void addMap(ma &um, string &s, ll n)
{
  REP(i, 1LL << (n))
  {
    string ts1 = "";
    string ts2 = "";
    REP(k, n)
    {
      if (i & BIT(k))
        ts1 += s[k];
      else
        ts2 += s[k];
    }
    auto pts = make_pair(ts1, ts2);
    um[pts]++;
  }
}

int main(void)
{
  ll n;
  cin >> n;
  string s;
  cin >> s;

  ma umL;
  ma umR;

  string sL = s.substr(0, n);
  string sR = s.substr(n);
  string rsR = sR;
  reverse(begin(rsR), end(rsR));

  OUT2(sL, rsR);
  addMap(umL, sL, n);
  addMap(umR, rsR, n);
  ll ans = 0;
  for (auto p : umL)
  {
    if (umR.find(p.first) != end(umR))
    {
      OUTPA(p.first);
      OUT2(p.second, umR[p.first]);
      ans += umR[p.first] * p.second;
    }
  }
  cout << ans << endl;

  return 0;
}

ll mod_pow(ll x, ll r)
{
  if (r == 0)
    return 1;
  else if (r == 1)
    return x % mod;
  else if (r % 2 == 0)
  {
    ll t = mod_pow(x, r / 2) % mod;
    return mod_mul(t, t);
  }
  else
  {
    ll t = mod_pow(x, r / 2) % mod;
    ll k = mod_mul(t, t);
    return (k % mod) * (x % mod);
  }
}
ll mod_add(ll a, ll b)
{
  return ((a % mod) + (b % mod)) % mod;
}

ll mod_mul(ll a, ll b)
{
  return ((a % mod) * (b % mod)) % mod;
}

ll mod_div(ll a, ll b)
{
  return mod_mul(a, mod_pow(b, mod - 2));
}

void make_fact(ll n)
{
  fac[0] = 1;
  rep(i, n)
  {
    fac[i + 1] = mod_mul(fac[i], i + 1);
  }
}

void make_invfact(ll n)
{
  invfac[n] = mod_pow(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; i--)
  {
    invfac[i] = mod_mul(invfac[i + 1], i + 1);
  }
}