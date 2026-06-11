#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string b;
  cin >> b;
  if (b == "A") cout << "T" << endl;
  else if (b == "T") cout << "A" << endl;
  else if (b == "C") cout << "G" << endl;
  else cout << "C" << endl;
  return 0;
}
