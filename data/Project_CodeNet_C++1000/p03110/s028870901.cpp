#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int n;
  cin >> n;
  double x;
  string u;
  double a = 0, b = 0;
  rep(i,n){
    cin >> x >> u;
    if(u == "JPY") a += x;
    else b += x;
  }
  cout << a + 380000*b <<endl;
  return 0;
}