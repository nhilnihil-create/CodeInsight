#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int a = stoi(s.substr(0,2)), b = stoi(s.substr(2,2));
  if (a > 12 || a == 0) {
    if (b > 12 || b == 0) cout << "NA" << endl;
    else cout << "YYMM" << endl;
  } else {
    if (b > 12 || b == 0) cout << "MMYY" << endl;
    else cout << "AMBIGUOUS" << endl;
  }
  return 0;
}