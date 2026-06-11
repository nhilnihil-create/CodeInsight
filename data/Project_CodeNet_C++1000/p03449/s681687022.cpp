#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<vector<int>> a(2,vector<int>(n));
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < n; j++){
      cin >> a.at(i).at(j);
    }
  }
  
  vector<int> c(n);
  
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= i; j++){
      c.at(i) += a.at(0).at(j);
    }
    for (int j = i; j < n; j++){
      c.at(i) += a.at(1).at(j);
    }
  }
  sort(c.begin(), c.end());
  cout << c.at(n - 1) << endl;
}