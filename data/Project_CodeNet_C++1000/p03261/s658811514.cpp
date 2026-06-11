#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  bool flag = true;
  vector<string> st(n);
  rep(i, n) {
    cin >> st[i];
  }
  rep(i,n) rep(j,i) {
    if(i == j) continue;
    if(st[j] == st[i]) flag = false;
  }
  if(flag) {
    for(int i = 0; i < n; i++){
      char s_last;
      if(i == 0) {
        s_last = st[i][st[i].size()-1];
        continue;
      }
      else {
        char s_first = st[i][0];
        if(s_first != s_last) {
          flag = false;
        }
        s_last = st[i][st[i].size()-1];
      }
    }
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

      
  