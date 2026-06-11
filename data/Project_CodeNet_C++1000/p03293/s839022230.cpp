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


string rotate(string s);

int main() {
  string s,t;
  cin >> s >> t;

  int n = s.size();
  for (int i=0; i<n; i++) {
    if (s==t) {
      cout << "Yes" << endl;
      return 0;
    }
    s = rotate(s);
  }
  cout << "No" << endl;
  return 0;
}

string rotate(string s){
  return s.substr(1) + s[0];
}
