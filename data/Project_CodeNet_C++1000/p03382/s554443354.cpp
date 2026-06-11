#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  int maxv = *max_element(a.begin(), a.end());
  double med = maxv/2.0;
  int ans = -1;
  int minv = 1e9;
  for(int i = 0; i < n; i++){
    if(maxv == a[i]) continue;
    if(abs(med - a[i]) < minv){
      ans = a[i];
      minv = abs(med - a[i]);
    }
  }
  cout << maxv << " " << ans << endl;
  return 0;

}
