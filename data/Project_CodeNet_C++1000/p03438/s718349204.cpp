#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool ok = false;
  vector<long long> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  for(int i = 0; i < n; i++) cin >> b.at(i);
  
  long long dis = 0, cnt = 0;
  for(int i = 0; i < n; i++){
    dis += b.at(i) - a.at(i);
    if(a.at(i) > b.at(i)) continue;
    cnt += (b.at(i) - a.at(i) + 1) / 2;
  }
  
  if(dis >= cnt) ok = true;
  
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}