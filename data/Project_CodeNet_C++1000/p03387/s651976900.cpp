#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> v(3);
  for(int i = 0; i<3;i++) cin >> v.at(i);
  sort(v.begin(),v.end());
  int n_min = v.at(0);
  int n_mid = v.at(1);
  int n_max = v.at(2);
  int ans = 0;
  if((n_max - n_mid) % 2 != (n_max - n_min) % 2) {
    n_max++;
    n_mid++;
    ans++;
  }
  ans += (n_max - n_mid);
  ans += (n_mid - n_min) % 2 == 0 ? (n_mid - n_min) / 2 : (n_mid - n_min) / 2 + 1;
  cout << ans << endl;
}