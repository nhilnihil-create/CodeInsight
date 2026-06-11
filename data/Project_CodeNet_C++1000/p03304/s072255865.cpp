#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

int main() {
  cout << setprecision(10) << fixed;
  ll n, m, d;
  cin >> n >> m >> d;
  if (d==0) cout << (double)(m-1)/n << endl;
  else cout << 2.0*(n-d)/(n*n)*(m-1) << endl;
  return 0;
}