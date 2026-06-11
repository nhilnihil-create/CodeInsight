#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b; cin >> a >> b;
  int m = max(a, b);
  string res = m<=8 ? "Yay!" : ":(";
  cout << res << endl;
  return 0;
}