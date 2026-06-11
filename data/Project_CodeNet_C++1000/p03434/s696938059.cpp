#include<bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> a(n);
  for(int &c : a) {
    cin >> c;
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int Alice = 0, Bob = 0;
  for(int i = 0; i < n; i++) {
    if(i %2 == 0) {
      Alice += a.at(i);
    }
    else {
      Bob += a.at(i);
    }
  }
  cout << max(Alice, Bob) - min(Alice, Bob) << endl;
}