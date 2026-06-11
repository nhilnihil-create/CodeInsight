#include <bits/stdc++.h>
using namespace std;

int main() {
 int a,b,c; cin >> a >> b >> c;
  int abmin=min(a,b);
  int abmax=max(a,b);
  if(c<=abmax && c>=abmin)cout << "Yes" << endl;
  else cout << "No" << endl;
}