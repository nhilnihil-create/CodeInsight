#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<ll> vec(n+2, 0);
  for (int i= 1; i < n+1; i++) {
    cin >> vec[i];
  }
  n += 2;
  ll total = 0;
  for (int i = 1; i < n; i++) {
    total += abs(vec[i-1] - vec[i]);
  }
  for (int i = 0; i < n-2; i++) {
    int a = abs(vec[i] - vec[i+1]) + abs(vec[i+1] - vec[i+2]);
    int b = abs(vec[i] - vec[i+2]);
    
    cout << total - a + b << endl;
  }
  
  return 0;
}