#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll a, b, c;
  cin >> a >> b >> c;
  cout << max(a, max(b, c)) - min(a, min(b, c)) << "\n";
}

