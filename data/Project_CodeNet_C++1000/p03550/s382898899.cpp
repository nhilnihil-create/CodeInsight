#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, Z, W;
  cin >> N >> Z >> W;
  vector<ll> A;
  A.push_back(Z);
  A.push_back(W);
  for (ll i = 0; i < N; ++i)
  {
    ll a;
    cin >> a;
    A.push_back(a);
  }
  cout << max(abs(A.at(N + 1) - A.at(1)), abs(A.at(N + 1) - A.at(N))) << endl;
}
