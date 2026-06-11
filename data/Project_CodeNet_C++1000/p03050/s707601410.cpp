#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  long long N;
  cin >> N;
  vector<int> divisor;
  for (long long i = 1; i * i <= N; i++)
  {
    if (N % i == 0)
    {
      divisor.push_back(i);
      if (i * i != N)
        divisor.push_back(N / i);
    }
  }

  long long ans = 0;
  for (long long a : divisor)
  {
    long long m = N / a - 1;
    if (m != 0 && N / m == N % m)
      ans += m;
  }
  cout << ans << endl;
  return 0;
}