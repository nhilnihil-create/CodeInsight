#include <bits/stdc++.h>
#include <set>
#include <numeric>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


// const double PI = acos(-1);
// int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }
// int a[12][12];
//平方根　= sqrt

int solve() {
  int r; cin >> r;

  if (r<1200) {
    cout << "ABC" << endl;
  }
  else if (r<2800) {
    cout << "ARC" << endl;
  }
  else {
    cout << "AGC" << endl;
 }
}


int main(){
  solve();
  return 0;
}
