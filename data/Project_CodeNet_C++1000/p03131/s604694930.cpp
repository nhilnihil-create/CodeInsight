#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
#define vall(x) (x).begin(), (x).end()
using namespace std;
using lli = long long int;
void YESNO(bool), YesNo(bool);
template <class T1, class T2>
bool chmin(T1 &l, const T2 &r);
template <class T1, class T2>
bool chmax(T1 &l, const T2 &r);
template <class T1, class T2>
void vadd(vector<T1> &v, T2 x);

#define int long long int

lli solve(long long K, long long A, long long B)
{
  // A+2回でB
  // 1回で1
  // B/(A+2)<=1/1
  lli ret = K + 1;

  // 1/0 -> A/0 -> 0/1 -> B/0 -> B-A/1 -> 2B-A/0

  K -= (A - 1);
  // A/0/A-1

  if (K <= 0)
    return ret;

  K--;
  // 0/1/A;
  if (K <= 0)
    return ret;

  K--;
  // B/0/A+1

  if (K == 0)
    return max(ret, B);

  // 残りK回できる. 2回でB-Aずつ増えていく
  return max(ret, B + (K / 2) * (B - A) + K % 2);
}

signed main()
{
  long long K;
  scanf("%lld", &K);
  long long A;
  scanf("%lld", &A);
  long long B;
  scanf("%lld", &B);
  cout << solve(K, A, B) << endl;
  return 0;
}

// -- lib
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }

template <class T1, class T2>
bool chmin(T1 &l, const T2 &r)
{
  return (l > r) ? (l = r, true) : false;
}

template <class T1, class T2>
bool chmax(T1 &l, const T2 &r)
{
  return (l < r) ? (l = r, true) : false;
}

template <class T1, class T2>
void vadd(vector<T1> &v, T2 x)
{
  for (auto &s : v)
    s += T2(x);
}
