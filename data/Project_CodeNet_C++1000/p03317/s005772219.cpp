#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> vec(n);
  pair<ll, ll> p = make_pair(-1, INF);
  rep(i, n) {
    cin >> vec[i];
  }
  cout << ceil((n - 1) / (k - 1.0)) << endl;
  return 0;
}