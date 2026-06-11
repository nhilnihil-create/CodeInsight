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
  int A, B, K;
  cin >> A >> B >> K;
  rep(i, K)
  {

    if (i % 2 == 0)
    {
      int tempA = A - A % 2;
      A = tempA / 2;
      B += tempA / 2;
    }
    else
    {
      int tempB = B - B % 2;
      A += tempB / 2;
      B = tempB / 2;
    }
  }
  cout << A << " " << B << endl;
  return 0;
}