#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int s;
  cin >> s;
  int ans = 0, sum = 0, m = 0;
  int a[s];
  rep(i, s) {
    cin >> a[i];
  	m = max(m, a[i]);
    sum += a[i];
  }
  cout << sum - m + m / 2 << endl;
  return 0;
}