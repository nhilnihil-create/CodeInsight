#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  ll sum = 0, cnt = 0;
  rep(i,n) {
    if(a[i]>b[i]) sum += a[i]-b[i];
    else cnt += (b[i]-a[i])/2;
  }
  cout << (sum>cnt? "No" : "Yes") << endl;
  return 0;
}