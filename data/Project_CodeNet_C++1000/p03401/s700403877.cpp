#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int a[n+2];
  a[0] = 0;
  a[n+1] = 0;
  rep1(i,n) cin >> a[i];

  ll sum = 0;
  for(int i = 0; i <= n; i++) sum += abs(a[i] - a[i+1]);
  
  for(int i = 0; i < n; i++)
  {
    cout << sum - abs(a[i+1] - a[i]) - abs(a[i+1] - a[i+2]) + abs(a[i] - a[i+2]) << endl;
  }
  
}