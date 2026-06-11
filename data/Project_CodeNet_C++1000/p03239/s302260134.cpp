#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,t;
  cin >> n >> t;
  vector<int> list;
  int a,b;
  for(int i=0; i<n; i++) {
    cin >> a >> b;
    if(b <= t) {
      list.push_back(a);
    }
  }
  if(list.empty()) {
    cout << "TLE" << endl;
  } else {
    sort(list.begin(),list.end());
    cout << list.at(0) << endl;
  }
}