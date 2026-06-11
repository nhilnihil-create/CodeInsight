#define _GLIBCXX_DEBUG // test only

#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);
  int a,b;
  cin >> a >> b;
  if(a>8||b>8) cout << ":(" << endl;
  else cout << "Yay!" << endl;
}