#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i,n) {
    cin >> a[i];
    b[i]=a[i];
  }
  sort(b.begin(),b.end());
  int c1 = b[n/2-1];
  int c2 = b[n/2];
  rep(i,n) {
    if(a[i]>=c2) cout << c1 << endl;
    else cout << c2 << endl;
  }
}
