#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0; i<(int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  double heikin=0;
  rep(i,n) {
    cin >> a[i];
    heikin+=a[i];
  }
  heikin/=n;
  double div=10000000;
  int ans=0;
  rep(i,n) {
    if (abs(heikin-a[i])<div) {
      div=abs(heikin-a[i]);
      ans=i;
    }
  }
  cout << ans << endl;
}