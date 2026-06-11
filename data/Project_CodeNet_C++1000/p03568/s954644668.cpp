#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  int n;
  cin >> n;
  vi a(n);
  rep(i, n) cin >> a[i];
  int ansa = 1;
  int ansb = 1;
  rep(i, n) {
    ansa *= 3;
    if(a[i] % 2 == 0) ansb *= 2;
  }
  cout << ansa - ansb << endl;
}