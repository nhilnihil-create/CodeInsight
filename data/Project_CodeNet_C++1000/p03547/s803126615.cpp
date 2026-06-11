#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  char x,y;
  cin >> x >> y;
  int a = x;
  int b = y;
  if(a > b) cout << ">" << endl;
  else if(a == b) cout << "=" << endl;
  else cout << "<" << endl;
}