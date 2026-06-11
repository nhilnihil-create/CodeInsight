#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)

char a[510][510];

int main(){
  rep(i,2) rep(j,3) cin >> a[i][j];
  bool ok = true;
  rep(j,3) if(a[1][j] != a[0][2-j]) ok = false;
  cout << (ok ? "YES" : "NO") << endl;
}
