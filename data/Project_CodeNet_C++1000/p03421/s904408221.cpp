#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;

using lli = long long int;
void YESNO(bool), YesNo(bool);
template <class T1, class T2>
bool chmin(T1 &l, const T2 &r);
template <class T1, class T2>
bool chmax(T1 &l, const T2 &r);

lli getLisLength(vector<lli> a)
{
  lli inf = 1e18;
  vector<lli> dp(a.size() + 3, inf);
  //inf=>INF
  rep(i, a.size())
  {
    *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
  }
  return lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
}
void test()
{
  const int N = 11;
  for (int i = 1; i <= N; i++)
  {
    cout << "length"
         << " " << i << endl;
    vector<lli> q;
    rep(j, i) q.push_back(j + 1);
    set<pair<int, int>> ans;
    map<pair<int, int>, vector<lli>> example;
    do
    {
      /*
      for (auto s : q)
        cout << s << " ";
        */
      lli ma = getLisLength(q);
      reverse(q.begin(), q.end());
      lli mi = getLisLength(q);
      ans.insert(make_pair(ma, mi));
      if (!example.count(make_pair(ma, mi)))
      {
        example[make_pair(ma, mi)] = q;
      }
      reverse(q.begin(), q.end());

    } while (next_permutation(q.begin(), q.end()));
    for (auto s : ans)
    {
      cout << s.first << " " << s.second << " :";
      for (auto j : example[s])
      {
        cout << j << " ";
      }
      cout << endl;
    }
  }
}
void solve(long long N, long long A, long long B)
{
  lli n = N;
  if (A * B < N)
  {
    cout << -1 << endl;
    return;
  }
  // bool rev = true;
  // if (A < B)
  // {
  //   rev = false;
  //   swap(A, B);
  // }
  vector<int> ans(A);
  ans[0] = B;
  N -= (B + A - 1);
  for (int i = 1; i < A; i++)
    ans[i] = 1;
  for (int i = 1; i < A; i++)
  {
    if (N >= B - 1)
    {
      ans[i] += B - 1;
      N -= B - 1;
    }
    else
    {
      ans[i] += N;
      N = 0;
    }
  }
  vector<vector<int>> calc(A);
  int cnt = 1;
  rrep(i, A)
  {
    rep(j, ans[i])
    {
      calc[i].push_back(cnt++);
    }
  }
  vector<lli> last;

  rep(i, A)
  {
    for (auto s : calc[i])
      last.push_back(s);
  }
  bool flag = false;
  auto cp = last;
  reverse(cp.begin(), cp.end());
  if (last.size() != n || getLisLength(last) != B || getLisLength(cp) != A)
  {
    cout << -1 << endl;
    return;
  }
  rep(i, n) cout << cp[i] << " ";
}

int main()
{
  //test();
  long long N;
  scanf("%lld", &N);
  long long A;
  scanf("%lld", &A);
  long long B;
  scanf("%lld", &B);
  solve(N, A, B);
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
