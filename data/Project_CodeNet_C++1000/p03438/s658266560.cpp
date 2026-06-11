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
  int N;
  cin >> N;
  vector<long long> a(N), b(N);
  long long count_a = 0, count_b = 0;
  rep(i, N)
  {
    cin >> a[i];
  }
  rep(i, N)
  {
    cin >> b[i];
  }
  rep(i, N)
  {
    if (a[i] > b[i])
    {
      count_b += a[i] - b[i];
    }
    else if (a[i] < b[i])
    {
      if (a[i] % 2 == b[i] % 2)
      {
        count_a += (b[i] - a[i]) / 2;
      }
      else
      {
        count_a += (b[i] + 1 - a[i]) / 2;
        count_b += 1;
      }
    }
  }

  long long M = count_a - count_b;
  if (M >= 0)
    cout
        << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}