#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>
int main() {
  int a, b; cin >> a >> b;
  int p = a+b;
  int x = a*b;
  int m = a-b;
  int l = max (p,x);
  int ans = max (l,m);
  cout << ans << endl;
}

