#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> list(3);
  int n;
  for(int i=0; i<3; i++) {
    cin >> list.at(i);
  }
  sort(list.begin(),list.end());
  cin >> n;
  for(int i=0; i<n; i++) {
    list.at(2) *= 2;
  }
  int ans = 0;
  for(int i=0; i<3; i++) {
    ans += list.at(i);
  }
  cout << ans << endl;
}