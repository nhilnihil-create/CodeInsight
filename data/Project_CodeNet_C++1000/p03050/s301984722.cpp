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
  long long tempN = N;
  vector<pair<int, int>> prime;
  bool is_prime = true;
  for (long long i = 2; i * i <= N; i++)
  {
    if (tempN % i == 0)
    {
      prime.push_back(make_pair(i, 0));
      while (tempN % i == 0)
      {
        tempN /= i;
        prime.back().second++;
      }
      is_prime = false;
    }
  }
  if (is_prime)
    prime.push_back(make_pair(N, 1));

  set<long long> st;
  st.insert(1);
  rep(i, prime.size()) rep(j, prime[i].second)
  {
    set<long long> temp_st = st;
    for (long long n : st)
    {
      temp_st.insert(n * prime[i].first);
    }
    st = temp_st;
  }

  long long ans = 0;
  for (long long a : st)
  {
    long long m = N / a - 1;
    if (m != 0 && N / m == N % m)
      ans += m;
  }
  cout << ans << endl;
  return 0;
}