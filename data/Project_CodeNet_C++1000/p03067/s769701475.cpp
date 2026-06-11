#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[3];
  for ( int i=0; i<3; i++ ) cin >> a[i];
  int x=a[2];
  sort(a,a+3);
  if ( a[1]==x ) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}