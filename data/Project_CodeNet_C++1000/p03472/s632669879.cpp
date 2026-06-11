#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

int w[100005];
int t[100005];
int main() {
  int n; ll m;
  cin >> n >> m;

  ll wmax = 0;
  for (int i = 1; i <= n; i++){
    cin >> w[i] >> t[i];
    if (w[i] > wmax)
      wmax = w[i];
  }

  sort(t+1, t+n+1);
  ll ans = 0;
  for (int i = n; i > 0; i--){
    if (m > 0){
      if (t[i] > wmax){
        ans++;
        m = m - t[i];
      }
      else 
        break;
    }
  }
  
  if (m > 0){
    ans = ans + m/wmax;
    if (m%wmax != 0)
      ans++;
    m = 0;
  }
  
  cout << ans << endl;
}