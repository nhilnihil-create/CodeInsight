#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;
//1125~
void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }

  ll ans = n;
  int num = 0;
  int si = 0;
  for(int i = 0; i < n; ++i)
  {
    while((num & a[i]) > 0) 
    {
      num ^= a[si];
      si++;
    }

    num ^= a[i];

    ans += (i - si);
    // cout << setw(5) << num << setw(3) << si << setw(3) << i;
    // cout << " add " << i - si << endl;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}