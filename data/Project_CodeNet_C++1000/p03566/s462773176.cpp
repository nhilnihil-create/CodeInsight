#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
// #define MOD 998244353
#define MEM_SIZE 101010
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()

template <typename T>
void DEBUG(T e)
{
  if (DEBUG_OUT == false)
    return;
  std::cout << e << " ";
}
template <typename T>
void DEBUG(const std::vector<T> &v)
{
  if (DEBUG_OUT == false)
    return;
  for (const auto &e : v)
  {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}
template <typename T>
void DEBUG(const std::vector<std::vector<T>> &vv)
{
  if (DEBUG_OUT == false)
    return;
  for (const auto &v : vv)
  {
    DEBUG(v);
  }
}
template <class T, class... Ts>
void DEBUG(T d, Ts... e)
{
  if (DEBUG_OUT == false)
    return;
  DEBUG(d);
  DEBUG(e...);
}
template <class T>
void corner(bool flg, T hoge)
{
  if (flg)
  {
    cout << hoge << endl;
    abort();
  }
}
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

//BELOW
void solve(void)
{
  int n;
  cin >> n;
  int t_sum = 0;
  vector<int> t(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> t[i];
    t_sum += t[i];
  }
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  vector<int> smax(t_sum + 1, 0);
  int ct = 1;
  smax[0] = v[0];
  smax[t_sum] = v.back();
  for (int i = 0; i < n; i++)
  {
    int tt = t[i];
    while (tt > 0)
    {
      smax[ct - 1] = v[i];
      ct++;
      tt--;
    }
  }
  // DEBUG(smax);

  vector<double> s1(t_sum * 2 + 1, 0);
  for (int i = 1; i <= 2 * t_sum; i++)
  {
    s1[i] = min(s1[i - 1] + 0.5, (double)smax[(i - 1) / 2]);
  }
  // DEBUG(smax);
  vector<double> s2(2 * t_sum + 1, 0);
  for (int i = 2 * t_sum - 1; i >= 0; i--)
  {
    s2[i] = min(s2[i + 1] + 0.5, (double)smax[(i) / 2]);
  }

  vector<double> speed(2 * t_sum + 1, 0);
  for (int i = 0; i < 2 * t_sum; i++)
  {
    speed[i] = min(s1[i], s2[i]);
  }

  // for (int i = 0; i < 2 * t_sum + 1; i++)
  // {
  //   cout << speed[i] << " " << s1[i] << " " << s2[i] << " " << i << endl;
  // }

  // DEBUG(speed);
  double dist = 0;
  for (int i = 0; i < 2 * t_sum; i++)
  {
    double a = speed[i] + speed[i + 1];
    dist += a / 2 / 2;
  }
  cout << dist << endl;

  return;
}
int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(11);
  solve();

  return 0;
}
