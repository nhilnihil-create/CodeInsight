#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int m = stoi(s.substr(5,2));
  if (m <= 4) cout << "Heisei" << endl;
  else cout << "TBD" << endl;
  return 0;
}
