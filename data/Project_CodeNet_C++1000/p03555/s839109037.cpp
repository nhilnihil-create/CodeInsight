#include <bits/stdc++.h>
using namespace std;

int main () {
  string a="abc";
  string b="abc";
  for (int i=0;i<3;++i) cin >> a[i];
  for (int i=0;i<3;++i) cin >> b[i];

  bool ans=true;
  for (int i=0;i<3;++i) {
    if (a[i]!=b[2-i]) ans=false;
  }

  if (ans) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
