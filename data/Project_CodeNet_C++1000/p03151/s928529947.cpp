#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main()
{
  ll N;
  cin >> N;

  vector<ll> A(N), B(N);
  ll a_sum = 0, b_sum = 0;
  rep(i,0,N-1)
  {
    cin >> A[i];
    a_sum += A[i];
  }
  rep(i,0,N-1)
  {
    cin >> B[i];
    b_sum += B[i];
  }

  if (a_sum < b_sum)
  {
    cout << -1 << endl;
    return 0;
  }

  bool ok = true;
  rep(i,0,N-1)
    if (A[i] < B[i])
      ok = false;

  if (ok)
  {
    cout << 0 << endl;
    return 0;
  }

  vector<ll> pool;
  rep(i,0,N-1)
  {
    if (A[i] > B[i])
      pool.push_back(A[i] - B[i]);
  }
  
  sort(pool.begin(), pool.end());

  bool is_touched = false;
  rep(i,0,N-1)
  {
    if (A[i] < B[i])
    {
      ll deficit = B[i] - A[i];
      while (0 < deficit)
      {
        ll last = *pool.rbegin();
        if (deficit < last)
        {
          last -= deficit;
          deficit = 0;
          pool.pop_back();
          pool.push_back(last);
          is_touched = true;
        }
        else
        {
          deficit -= last;
          pool.pop_back();
          is_touched = false;
        }
      }
    }
  }

  ll ans = N - pool.size();
  if (is_touched) ans++;
  cout << ans << endl;
  return 0;
}
