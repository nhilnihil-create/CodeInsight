#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c; cin >> n >> m >> c;
  vector<int> b(m);
  for(int &k : b) {
    cin >> k;
  }
  vector<vector<int>> a(n, vector<int>(m));
  for(vector<int> &k : a) {
    for(int &l : k) {
      cin >> l;
    }
  }
  int codes, count = 0;
  for(int i = 0; i < n; i++) {
    codes = c;
    for(int j = 0; j < m; j++) {
      codes += a.at(i).at(j) * b.at(j);
    }
    if(codes > 0) {
      count++;
    }
  }
  cout << count << endl;
}