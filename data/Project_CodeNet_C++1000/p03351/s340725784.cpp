#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  bool flag = false;
  if(abs(a-c)<=d) flag = true;
  else if(abs(a-b)<=d && abs(b-c)<=d) flag = true;
  
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}