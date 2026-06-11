#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int n,x;
  cin >> n >> x;
  
  int a[n+1];
  rep(i,n) cin >> a[i];
  a[n] = x;
  sort(a,a+(n+1));
  
  int dist[n];
  rep(i,n)
  {
    dist[i] = a[i+1] - a[i];
  }
  
  int gc = 0;
  rep(i,n)
  {
    gc = gcd(gc,dist[i]);
  }
  
  cout << gc << endl;
}
