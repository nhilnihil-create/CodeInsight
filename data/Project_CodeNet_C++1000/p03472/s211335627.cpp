#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  int n, h;
  cin >> n >> h;
  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];
  sort(a.begin(),a.end());
  int max_a = a[n-1];
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  int cnt = 0;
  while (h > 0 && b[cnt] >= max_a) {
    h -= b[cnt];
    cnt++;
  }
  while (h > 0) {
    h -= max_a;
    cnt++;
  }
  cout << cnt << endl;
}