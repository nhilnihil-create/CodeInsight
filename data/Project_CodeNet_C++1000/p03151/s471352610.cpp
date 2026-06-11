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
  vector<long long> dist(N);
  rep(i, N)
  {
    long long A;
    cin >> A;
    dist[i] += A;
  }

  rep(i, N)
  {
    long long B;
    cin >> B;
    dist[i] -= B;
  }
  long long ans = 0;
  long long sum = 0;
  rep(i, N)
  {
    if (dist[i] < 0)
    {
      ans++;
      sum += dist[i];
    }
  }
  RSORT(dist);
  rep(i, N)
  {
    if (sum >= 0)
      break;

    if (dist[i] < 0)
      break;
    sum += dist[i];
    ans++;
  }
  if (sum < 0)
    ans = -1;
  cout << ans << endl;
  return 0;
}