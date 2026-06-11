#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

const ll MOD = 1000000007;
const ll INF = 1e18; //1*10^18
const double PI = 3.14159265;

int ctoi(char c)
{
  if (c >= '0' && c <= '9')
  {
    return c - '0';
  }
  return 0;
}

ll powll(ll a, ll n)
{ //O(log n)
  ll res = 1;
  while (n > 0)
  {
    if (n & 1) //(n & 1)=(n % 2 !=0)
    {
      res = res * a;
    }
    a = a * a;
    n >>= 1; //(n & 1)=(n % 2 !=0)
  }
  return res;
}

ll modpow(ll a, ll n, ll mod) //O(log n)
{
  ll res = 1;
  while (n > 0)
  {
    if (n & 1) //(n & 1)=(n % 2 !=0)
    {
      res = res * a % mod;
    }
    a = a * a % mod;
    n >>= 1; //(n>>=1)=(n/2)
  }
  return res;
}

int ReturnDigit(ll num)
{
  string number = to_string(num);
  return number.length();
}

const ll MAX = 1e4;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

struct UnionFind
{
  vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

  UnionFind(int N) : par(N)
  { //最初は全てが根であるとして初期化
    for (int i = 0; i < N; i++)
      par[i] = i;
  }

  int root(int x)
  { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y)
  {                   // xとyの木を併合
    int rx = root(x); //xの根をrx
    int ry = root(y); //yの根をry
    if (rx == ry)
      return;     //xとyの根が同じ(=同じ木にある)時はそのまま
    par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
  }

  bool same(int x, int y)
  { // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main()
{
  // srand((unsigned int)time(NULL));//--> rand()
  ll i, j, k, l, ans = 0;
  ll n;
  cin >> n;

  if (n != 1)
  {
    // ans += n - 1;
  }

  for (i = 1; i * i <= n; i++)
  {
    // cout << i << ' ' << n % i << ' ' << n % (i - 1) << endl;
    if (n % i == 0)
    {
      ll m = (n / i) - 1;
      if (m > i)
      {
        ans += m;
      }
    }
  }
  cout << ans << endl;
}
