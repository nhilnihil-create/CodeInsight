#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main() {
  int n; cin >>n;
  vector<int> x(n),c(n);
  rep(i,n) {
    cin >>x[i];
    c[i]=x[i];
  }
  sort(x.begin(), x.end());
  rep(i,n){
    if(c[i]<x[n/2]) cout << x[n/2] << endl;
    else cout << x[n/2-1] << endl;
  }
  return 0;
}