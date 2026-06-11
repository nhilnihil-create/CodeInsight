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
  int n; cin >> n;

  string n_str = to_string(n);
  // if (n_str[0]=='1') n_str[0]='9'

  int n_size = n_str.size();
  for (int i =0; i< n_size; i++) {
    if (n_str[i] == '9') n_str[i] = '1';
    else  n_str[i] = '9';
    if (i==2) break;
  }
  cout << n_str << endl;

}

int main() {
  solve();
  return 0;
}
