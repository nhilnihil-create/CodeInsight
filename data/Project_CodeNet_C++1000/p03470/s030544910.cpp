#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for(int i = 0;  i < n; i++) cin >> d.at(i);
  
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  int ans = 0, size = 1000;
  for(int i = 0; i < n; i++){
    if(size > d.at(i)){
      size = d.at(i);
      ans++;
    }
  }
  
  cout << ans << endl;
}