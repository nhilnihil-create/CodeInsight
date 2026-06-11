#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  
  if (n==1) cout << s << endl;
  else {
    bool ok = true;
    rep(i,n-1) if (s[i+1] != '9') ok = false;
    if (ok) cout << s[0] - '0' + 9 * (n-1) << endl;
    else cout << s[0] - '1' + 9 * (n-1) << endl;
  }
}