#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,a;
  map<int,int> b;
  for (cin >> N; N; b[a]++, N--) {
    cin >> a;
  }
  a = 0;
  for (auto p : b) {
    if (p.second >= p.first) {
      a += p.second-p.first;
    } else {
      a += p.second;
    }
  }
  cout << a;
}