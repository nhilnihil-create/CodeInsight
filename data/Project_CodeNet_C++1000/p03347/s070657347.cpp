#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  bool yes = true;
  for(int i=0;i<n;i++) {
    cin >> a[i];
    if(i == 0 && a[i] != 0) yes = false;
    if(i != 0 && a[i] > a[i-1] + 1) yes = false;
  }
  if(!yes) cout << -1 << endl;
  else {
    long long ans = 0;
    for(int i=0;i<n;i++) {
      if(i == 0) continue;
      if(a[i] == a[i-1] + 1) continue;
      else ans += a[i-1];
    }
    ans += a.back();
    cout << ans << endl;
  }
  return 0;
}
