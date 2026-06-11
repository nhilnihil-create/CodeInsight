#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N; cin >> N;
  vector<int> a(N);
  rep(i,N) cin >> a[i];
  sort(a.rbegin(), a.rend());
  int alice = 0, bob = 0;
  rep(i,N) {
    if (i%2==0) alice += a[i];
    else bob += a[i];
  }
  cout << alice - bob << endl;
  return 0;
}