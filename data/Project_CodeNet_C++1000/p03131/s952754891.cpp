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
  long long K, A, B;
  cin >> K >> A >> B;
  long long bisket = 1;
  long long T = -A + B - 2;
  if (T <= 0)
    bisket += K;
  else
  {
    long long M = max((K - A + 1) / 2, (long long)0);
    bisket = K + 1 + M * (B - A - 2);
  }
  cout << bisket << endl;
  long long ans = 48518828981938099;
  return 0;
}