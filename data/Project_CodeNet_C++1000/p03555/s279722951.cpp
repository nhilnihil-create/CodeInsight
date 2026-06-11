#include <bits/stdc++.h>
using namespace std;
int main(){
  char c[3], d[3];
  cin >> c >> d;
  cout << (c[0] == d[2] && c[1] == d[1] && c[2] == d[0] ? "YES" : "NO") << endl;;
}