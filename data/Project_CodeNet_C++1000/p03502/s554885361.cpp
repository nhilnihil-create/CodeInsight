#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int keta(int x) {
  int ans = 0;
  while (x > 0) {
    ans += x%10;
    x /= 10;
  }

  return ans;
}

int main() {
  int n; cin >> n;
  if (n%keta(n) == 0) cout <<"Yes"<< endl;
  else cout << "No" << endl;
  return 0;
}