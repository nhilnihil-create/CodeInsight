#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
using namespace std;


void solve(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<int> aida(n + 1);
  aida[0] = abs(a[0]);
  for(int i = 1; i < n; i++){
    aida[i] = abs(a[i] - a[i - 1]);
  }
  aida[n] = abs(a[n - 1]);
  int sum = 0;
  for(int i = 0; i <= n; i++) sum += aida[i];
  int ans = 0;
  ans = sum - aida[0] - aida[1] + abs(a[1]);
  cout << ans << endl;
  for(int i = 1; i < n - 1; i++){
    ans = sum - aida[i] - aida[i + 1] + abs(a[i + 1] - a[i - 1]);
    cout << ans << endl;
  }
  ans = sum - aida[n - 1] - aida[n] + abs(a[n - 2]);
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
