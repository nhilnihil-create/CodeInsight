#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  char x, y;
  cin >> x >> y;
  if(x == y) cout << "=" << endl;
  else if(x > y) cout << ">" << endl;
  else if(x < y) cout << "<" << endl;
}