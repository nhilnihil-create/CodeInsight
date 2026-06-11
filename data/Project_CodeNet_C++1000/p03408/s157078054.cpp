#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < (int)(n);i++)
int main() {
  int n, m, M = 0, x;
  cin >> n;
  string s;
  map<string, int> v;
  rep(i, n) {
    cin >> s;
    v[s]++;
  }
  cin >> m;
  rep(i, m) {
    cin >> s;
    v[s]--;
  }
  for(auto p : v) {
    x = p.second;
    if(x > M) M = x;
  }
  cout << M << endl;
}