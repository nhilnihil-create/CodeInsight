#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n >> k;
  vector<int> a(200010);
  for(int i = 0; i < n; i++){
    int c; cin >> c;
    a.at(c)++;
  }
  sort(a.rbegin(), a.rend());
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(i >= k) ans += a.at(i);
  }
  cout << ans << endl;
}