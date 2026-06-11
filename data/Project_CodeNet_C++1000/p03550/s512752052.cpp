#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << fixed;

  int n, z, w;
  cin >> n >> z >> w;
  
  vector<int> a(n);
  rep(i, n) { cin >> a[i]; }

  if (n == 1) { cout << abs(a[0]-w) << endl; }
  else { cout << max(abs(a[n-1]-w), abs(a[n-1]-a[n-2])) << endl; }

  return 0;
}