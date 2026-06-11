#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  map<char, ll> s;
  s['M'] = s['A'] = s['R'] = s['C'] = s['H'] = 0;
  for (ll i = 0; i < n; i++)
  {
    string tmp;
    cin >> tmp;
    s[tmp[0]]++;
  }
  ll ans =
      (s['M'] * s['A'] * s['R']) +
      (s['M'] * s['A'] * s['C']) +
      (s['M'] * s['A'] * s['H']) +
      (s['M'] * s['R'] * s['C']) +
      (s['M'] * s['R'] * s['H']) +
      (s['M'] * s['C'] * s['H']) +
      (s['A'] * s['R'] * s['C']) +
      (s['A'] * s['R'] * s['H']) +
      (s['A'] * s['C'] * s['H']) +
      (s['R'] * s['C'] * s['H']);
  cout << ans << endl;
}
