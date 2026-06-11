#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n; cin >> n;
  vector<ll> a;

  rep(i,n) {
    ll tmp;cin >> tmp;
    a.push_back(tmp);
  }

  sort(a.begin(), a.end());

  cout << a[a.size()-1] - a[0] << endl;
  return 0;
}