#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> c(n);
  int sum = 0;
  int inf = 0;
  rep(i, n) cin >> v[i];
  rep(i, n) cin >> c[i];
  rep(i, n) {
    sum += v[i] - c[i];
    if(sum > inf) inf = sum;
    else sum -= v[i] - c[i];
  }
  cout << inf << endl;
}