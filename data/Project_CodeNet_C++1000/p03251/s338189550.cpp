#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)
typedef long long ll;


ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;

  /* input */
  vector<int> x_coord(n);
  vector<int> y_coord(m);
  rep(i, n) {
      cin >> x_coord[i];
  }
  rep(i, m) {
      cin >> y_coord[i];
  }

  sort(x_coord.begin(), x_coord.end());
  sort(y_coord.begin(), y_coord.end());
  /* check */
  string ans = "War";
  rep(j, n) {
      if ((x_coord[j] > x && x_coord[j] <= y) && 
          (x_coord[n-1] < y_coord[0]) &&
          (y_coord[0] > x && y_coord[0] <= y)) {
          ans = "No War";
      }
  }
  rep(j, m) {
      if ((x_coord[j] > x && x_coord[j] <= y) && 
          (x_coord[n-1] < y_coord[0]) &&
          (y_coord[0] > x && y_coord[0] <= y)) {
          ans = "No War";
      }
  }
  cout << ans << endl;
}
