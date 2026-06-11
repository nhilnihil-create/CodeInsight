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



void solve() {
  int k; cin >> k;
  int even=0,odd=0;
  for (int i=1; i <=k; i++) {
    if (i%2 == 0) odd++;
    else even++;
  }
  cout << even*odd << endl;

}

int main() {
  solve();
  return 0;
}
