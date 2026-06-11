#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n, k;
  cin >> n >> k;
  int a[n];
  int sum = 0;
  rep(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  k -= sum;
  int ans = n;
  sort(a, a + n);
  ans = ans + k / a[0];
  cout << ans << endl;
  
  
      
    
  return 0;
}