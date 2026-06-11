# include <bits/stdc++.h>
using namespace std;
int main () {
  int n;
  cin >> n;
  vector<int> list(n);
  for(int i=0; i<n; i++) {
    cin >> list.at(i);
  }
  sort(list.begin(),list.end());
  list.back() = list.back()/2;
  int ans=0;
  for(int i=0; i<n; i++) {
    ans += list.at(i);
  }
  cout << ans << endl;
}