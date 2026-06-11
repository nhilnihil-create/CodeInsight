#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n;
  cin >> n;
  ll a[n];
  rep(i,n) cin >> a[i];
  sort(a,a + n);
  cout << a[n - 1] - a[0] << endl;
  return 0;
}