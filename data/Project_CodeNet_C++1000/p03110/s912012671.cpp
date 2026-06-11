#include <bits/stdc++.h>
#include <set>
#include <numeric>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }




int main() {
  int n;
  cin >> n;

  double y=0;
  for (int i =0;i<n;i++) {
    double num;
    string s;
    cin >> num >> s;
    if (s=="BTC") {
      y += num*380000;
    }
    else {
      y += num;
    }
  }
  cout << y << endl;

}