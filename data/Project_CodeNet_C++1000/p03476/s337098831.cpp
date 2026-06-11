#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int q;
  cin >> q;
  set<int> num;
  for(int i = 2; i <= 100100; i++) {
    bool ok = true;
    for(int j = 2; j*j <=i; j++) {
      if(i%j==0) {
        ok = false;
        break;
      }
    }
    if(ok) num.insert(i);
  }
  int a[100100];
  a[0] = 0;
  a[1] = 0;
  for(int i = 2; i <= 100100; i++) {
    a[i] = a[i-1];
    if(num.count(i)&&num.count((i+1)/2)) a[i]++;
  }
  vector<int> l(q), r(q);
  rep(i,q) cin >> l[i] >> r[i];
  rep(i,q) cout << a[r[i]] - a[l[i]-1] << endl;
  return 0;
}