#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string s;
  cin >> s;
  int cnt = 0;
  bool flag = true;
  int maxm = 0;

  rep(i, s.size()) {
    if(s[i] == 'A'||s[i] == 'T'||s[i] == 'C'||s[i] =='G') {
      flag = false;
      cnt++;
      maxm = max(maxm, cnt);
    }
    else flag = true;
    if(flag) cnt = 0;
  }
  cout << maxm << endl;
}