#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,m,x,a[200],f = 0,b = 0;
  cin >> n >> m >> x;
  for(int i = 0; i < m; i++) {
    cin >> a[i];
    if(x > a[i]) f++;
    else b++;
  }
  if(f > b) cout << b << endl;
  else cout << f << endl;
}