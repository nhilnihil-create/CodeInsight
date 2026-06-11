#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b, c, d; cin >> a >> b >> c >> d;
  string res = "No";
  if(abs(a-c) <= d) res = "Yes";
  if(abs(a-b) <= d && abs(b-c) <= d) res = "Yes";
  cout << res << endl;
  return 0;
}