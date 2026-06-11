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
  vector<long long> A(N);
  rep(i, N)
  {
    cin >> A[i];
  }
  vector<long long> left(N + 1), right(N + 1);
  rep(i, N)
  {
    left[i + 1] = left[i] + A[i];
  }
  map<long long, long long> count;
  rep(i, N + 1)
  {
    count[left[i]]++;
  }
  long long ans = 0;
  for (pair<long long, long long> P : count)
  {
    if (P.second < 1)
      continue;
    ans += P.second * (P.second - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}