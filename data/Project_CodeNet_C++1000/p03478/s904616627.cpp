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
  int n,a,b; cin >> n >> a >> b;
  int cnt = 0;
  rep(i,n+1) {
    if (keta(i)>=a && keta(i)<=b) cnt+=i;
  }

  cout << cnt << endl;
  return 0;
}