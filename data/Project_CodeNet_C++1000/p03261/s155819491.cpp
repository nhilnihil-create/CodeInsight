#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> w(n);
  rep(i,n) cin >> w[i];
  
  bool ok = true;
  rep(i,n) {
    for (int j=i+1; j<n; j++) {
      if (w[i]==w[j])
        ok = false;
    }
  }
  rep(i,n-1) {
    if (w[i].back() != w[i+1].front())
      ok = false;
  }
  
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}