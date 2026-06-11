#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n;
  cin >> n;
  
  ll l[3]={2, 1, 0};
  if (n==1) {
    cout << 1 << endl;
  } else {
    rep(i,n-1) {
      l[2]=l[0]+l[1];
      l[0]=l[1];
      l[1]=l[2];
    }
    cout << l[2] << endl;
  }

  return 0;
}