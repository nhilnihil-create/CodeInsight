#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string s;
  cin >> s;
  string y = s.substr(0, 4);
  string m = s.substr(5, 2);
  string d = s.substr(8, 2);
  int Y = stoi(y);
  int M = stoi(m);
  int D = stoi(d);
  if(Y <= 2019 && M <= 4 && D <= 30) cout << "Heisei" << endl;
  else cout << "TBD" << endl;
}