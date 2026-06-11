#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  string s;
  cin >> s;
  if(s =="abc" || s=="acb" || s =="bca" || s=="cba" || s=="bac" || s == "cab") cout << "Yes" << endl;
  else cout << "No" << endl;
}