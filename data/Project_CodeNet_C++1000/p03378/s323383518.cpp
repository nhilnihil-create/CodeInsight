#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x; cin >> n >> m >> x;
  vector<int> ai(m);
  for(int &c : ai) {
    cin >> c;
  }
  int smaller = 0, bigger = 0;
  for(int i = 0; i < m; i++) {
    if(ai.at(i) < x) {
      smaller++;
    }
    else {
      bigger++;
    }
  }
  cout << min(smaller, bigger) << endl;
}