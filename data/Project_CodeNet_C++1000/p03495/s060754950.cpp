#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }
  sort(v.begin(), v.end());
  
  vector<int> w(v.at(n - 1));
  for (int i = 0; i < n; i++) {
    w.at(v.at(i) - 1)++;
  }
  sort(w.begin(), w.end());
  reverse(w.begin(), w.end());
  
  int s = 0;
  if (k < w.size()) {
    for (int i = 0; i < k; i++) {
      s += w.at(i);
    }
  }
  else {
    for (int i = 0; i < w.size(); i++) {
      s += w.at(i);
    }
  }
  cout << n - s << endl;
}