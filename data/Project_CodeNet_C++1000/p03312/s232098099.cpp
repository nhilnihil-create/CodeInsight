#include <bits/stdc++.h>
#include <iostream>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_r(i, n) for (int i = n - 1; i >= 0; i--)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())
#define bit(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

#define INF bit(60)
#define pb push_back
#define mod 1000000007

using namespace std;
using uif = uint_fast64_t;
using ll = long long int;
using tTree = __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

#define FACSIZE 200002

ll invfac[FACSIZE];
ll fac[FACSIZE];

template <class T>
bool chmax(T &, const T &);
template <class T>
bool chmin(T &, const T &);
ll gcd(ll, ll);
ll powLL(ll x, ll y);

ll mod_pow(ll, ll);
ll mod_add(ll, ll);
ll mod_mul(ll, ll);
ll mod_div(ll, ll);
ll comb(ll, ll);
void make_fact(ll);
void make_invfact(ll);
void fact_init();

int main(void)
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> total(n);
  rep(i, n)
  {
    cin >> a[i];
    if (i == 0)
      total[0] = a[0];
    else
      total[i] = total[i - 1] + a[i];
  }

  ll ans = LLONG_MAX;

  for (ll i = 1; i < n - 1; i++)
  {

    ll base = total[i];
    ll sum = total[n - 1];
    ll idx = i;
    ll lL = 0, lR = idx + 1;
    ll rL = idx + 1, rR = n;
    auto beg = begin(total);
    //ll en=en(total);
    auto itrL = lower_bound((beg + (lL)), (beg + (lR)), base / 2);
    auto itrR = lower_bound((beg + (rL)), (beg + (rR)), (base + sum) / 2);

    ll p, q, r, s;

    if (itrL == beg)
    {
      p = *beg;
      q = base - p;
    }
    ///*
    else if (itrL == (beg + (lR - 1)))
    {
      p = *(--itrL);
      q = base - p;
    }
    //*/
    else
    {
      ll p1 = *itrL;
      ll q1 = base - p1;
      ll p2 = *(--itrL);
      ll q2 = base - p2;
      ll c1 = abs(p1 - q1);
      ll c2 = abs(p2 - q2);
      if (c2 > c1)
      {
        p = p1;
        q = q1;
      }
      else
      {
        p = p2;
        q = q2;
      }
    }

    if (itrR == (beg + (rL)))
    {
      r = *(beg + (rL)) - base;
      s = sum - r - base;
    }
    else if (itrR == (beg + (rR - 1)))
    {
      r = *(--itrR) - base;
      s = sum - r - base;
    }
    else
    {
      ll r1 = *itrR - base;
      ll s1 = sum - base - r1;
      ll r2 = *(--itrR) - base;
      ll s2 = sum - base - r2;
      ll c1 = abs(r1 - s1);
      ll c2 = abs(r2 - s2);
      if (c2 > c1)
      {
        r = r1;
        s = s1;
      }
      else
      {
        r = r2;
        s = s2;
      }
    }

    ll c1 = min({p, q, r, s});
    ll c2 = max({p, q, r, s});

    ans = min(ans, c2 - c1);
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

void fact_init()
{
  make_fact(FACSIZE - 1);
  make_invfact(FACSIZE);
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

ll comb(ll n, ll r)
{

  return mod_mul(mod_mul(fac[n], invfac[r]), invfac[n - r]);
}
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

ll qp(ll a, ll b)
{
  ll ans = 1LL;
  do
  {
    if (b & 1LL)
      ans = 1LL * mod_mul(ans, a) % mod;
    a = 1LL * mod_mul(a, a) % mod;
  } while (b >>= 1LL);
  return ans;
}
ll qp(ll a, ll b, ll mo)
{
  ll ans = 1LL;
  do
  {
    if (b & 1LL)
      ans = 1LL * (ans % mo) * (a % mo);
    a = 1LL * (a % mo) * (a % mo);
  } while (b >>= 1LL);
  return ans;
}
ll gcd(ll a, ll b)
{
  return b ? gcd(b, a % b) : a;
}
ll powLL(ll x, ll y)
{
  ll ans = 1LL;
  for (ll i = 0LL; i < y; i++)
    ans *= x;
  return ans;
}