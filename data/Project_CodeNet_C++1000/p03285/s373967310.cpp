#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  bool ans = false;
  for(int i = 0; i <= (n/4)+1; i++) {
    for(int j = 0; j <= (n/7)+1; j++) {
      if(n == (4*i) + (7*j)) ans = true;
    }
  }
  
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}