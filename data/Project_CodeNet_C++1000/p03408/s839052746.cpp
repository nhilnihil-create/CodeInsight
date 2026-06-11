#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int n, m;

  cin >> n;
  vector<string> blue(n);
  for (int i = 0; i < n; i++) {
    cin >> blue.at(i);
  }
  
  cin >> m;
  vector<string> red(m);
  for (int i = 0; i < m; i++) {
    cin >> red.at(i);
  }
  
  int max_point=0;
  for (int i = 0; i < n; i++) {
    int point = 0;
    string word = blue.at(i);
    for (int j = 0; j < n; j++) {
      if (blue.at(j) == word) {
        point++;
      }
    }
    for (int k = 0; k < m; k++) {
      if (red.at(k) == word) {
        point--;
      }
    }
    
    if (point > max_point) {
      max_point = point;
    }
  }
  
  cout << max_point << endl;
}