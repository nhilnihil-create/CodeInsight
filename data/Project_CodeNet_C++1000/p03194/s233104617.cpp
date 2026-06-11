#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());
using ll = long long;
using P = pair<int,int>;

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

vector<pair<long long, long long>> enum_divisor(long long n)
{
  vector<pair<long long, long long>> dst;
  long long N = n;
  for(long long i = 2; i * i <= n; i++)
  {
    if(N % i != 0)
      continue;

    dst.push_back(make_pair(i, 0));
    while(N % i == 0)
    {
      dst.back().second++;
      N /= i;
    }
  }
  if(N >= 2)
    dst.push_back(make_pair(N, 1));
  sort(dst.begin(), dst.end());
  return dst;
}
int main()
{
  long long N, p;
  cin >> N >> p;
  long long ans = 1;
  auto factors = enum_divisor(p);
  rep(i, factors.size())
  {
//    cout << factors[i].first << ", " << factors[i].second << endl;
    if(factors[i].second >= N)
      ans *= pow(factors[i].first, factors[i].second / N);
  }
  cout << ans << endl;
  return 0;
}