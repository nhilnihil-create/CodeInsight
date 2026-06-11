#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

const int INF = 1e9;

int main()
{
  int n;
  cin >> n;
  
  vector<ll> a(n);
  int cnt = 0;
  rep(i, n)
  {
    cin >> a[i];
    if(a[i] < 0) cnt++;
    a[i] = abs(a[i]);
  }
  
  sort(a.begin(), a.end());
  
  ll sum = 0;
  rep(i, n) sum += a[i];
  
  if(cnt%2 == 0) cout << sum << endl;
  else cout << sum - a[0]*2 << endl;
  
  return 0;
}