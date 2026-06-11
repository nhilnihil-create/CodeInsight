#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
   for (int i = 0; i < m; i++) {
     cin >> b.at(i);
   }
  vector<vector<int>> data(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> data.at(i).at(j);
    }
  }
    int kauto = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        kauto += data.at(i).at(j) * b.at(j);
        if (j == m - 1) {
          if (kauto + c > 0) {
            count++;
          }
            kauto = 0;
          
        }
      }
    }
  cout << count << endl;
}