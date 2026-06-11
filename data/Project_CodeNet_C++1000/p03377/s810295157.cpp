#include <bits/stdc++.h>
#include <set>
#define rep(i,n) for (int i =0; i < (n); ++i)
using namespace std;


int main() {
  int a,b,x;
  cin >> a >> b >> x;
  int c = a + b;
  if (a <= x) {
    if (c >= x) cout << "YES";
    else cout << "NO";
  }
  else cout << "NO";
  cout << endl;

}
