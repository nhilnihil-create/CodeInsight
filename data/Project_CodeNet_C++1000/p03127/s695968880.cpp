#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define rep(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
using namespace std;

int gcd(int a, int b) {
  if(a % b == 0) return b;
  return gcd(b, a%b);
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, 0, n) cin >> v[i];
  int m = v[0];
  rep(i, 1, n) {
    m = gcd(m, v[i]);
  }
  cout << m << "\n";
}