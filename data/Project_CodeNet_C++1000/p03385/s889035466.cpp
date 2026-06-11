#include <bits/stdc++.h>
using namespace std;

int main () {
  string s;
  cin >> s;

  int a=s[0]+s[1]+s[2];
  int b='a'+'b'+'c';

  if(a==b) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
