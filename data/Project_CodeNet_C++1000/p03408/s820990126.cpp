#include<bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<string> bl(n);
  for(int i = 0; i < n; ++i) {
    cin >> bl[i];
  }

  int m; cin >> m;
  vector<string> rd(m);
  for(int i = 0; i < m; ++i) {
    cin >> rd[i];
  }

  int mx = 0;
  for(int i = 0; i < n; ++i) {
    int sum = 0;

    for(int j = 0; j < n; ++j) {
      if(bl[i] == bl[j]) ++sum;
    }

    for(int j = 0; j < m; ++j) {
      if(bl[i] == rd[j]) --sum;
    }

    mx = max(mx, sum);
  }
  cout << mx << "\n";
}