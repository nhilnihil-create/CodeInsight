#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  int x, y, z, k; cin >> x >> y >> z >> k;
  vector<lint> a(x), b(y), c(z);
  for(int i = 0; i < x; i++) cin >> a[i];
  for(int i = 0; i < y; i++) cin >> b[i];
  for(int i = 0; i < z; i++) cin >> c[i];
  vector<lint> data;
  for(int i = 0; i < x; i++){
    for(int j = 0; j< y; j++) data.push_back(a[i] + b[j]);
  }
  sort(data.begin(), data.end(), greater<lint>());
  vector<lint> data2;
  for(int i = 0; i < min(k, int(data.size())) ; i++){
    for(int j = 0; j < z; j++) data2.push_back(data[i] + c[j]);
  }
  sort(data2.begin(), data2.end(), greater<lint>());
  for(int i = 0; i < k; i++) cout << data2[i] << '\n';
}