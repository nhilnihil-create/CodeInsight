#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;

int main() {
  
  int a,b,x;
  cin >> a >> b >> x;

  bool ans = false;
  if (a <= x && a+b > x) ans = true;
  
  cout << ((ans) ? "YES" : "NO") << endl;
   
}