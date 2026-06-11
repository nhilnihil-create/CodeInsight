#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> list(n);
  int total = 0;
  for(int i=0; i<n; i++) {
    cin >> list.at(i);
    total += list.at(i);
  }
  sort(list.begin(),list.end());
  int max = list.back();
  total -= max;
  if(max < total) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}