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




void solve() {
  int r,d,exit;
  cin >> r >> d >> exit;
  int before=0;
  int cnt = 9;
  while(cnt>=0){
    before = r*exit - d;
    exit = before;
    cout << before << endl;
    --cnt;
  }
  return ;
}

int main() {
  solve();
  return 0;
}
