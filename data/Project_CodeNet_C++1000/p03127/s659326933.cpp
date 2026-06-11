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
  
  ll a[n];
  rep(i,n)
  {
    cin >> a[i];
  }

  int gc = a[0];
  rep(i,n)
  {
    gc = gcd(a[i],gc);
  }
  
  cout << gc << endl;
}
