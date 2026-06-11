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
  ll a[n + 1];
  a[0] = 2;
  a[1] = 1;
  for(int i = 2; i <= n; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }
    
  
  
  
  cout << a[n] << endl;

  return 0;
}