#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> sort_x(n), x(n);
  rep(i,n) {
    int a;
    cin >> a;
    x[i] = a;
    sort_x[i] = a;
  }
  sort(sort_x.begin(), sort_x.end());
  int med = n/2;
  int median_big = sort_x[med];
  int median_small = sort_x[med-1];

  rep(i,n) {
    if (x[i] >= median_big) cout << median_small << endl;
    else cout << median_big << endl;
  }
  return 0;
}