#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n,d,x,ans=0;
  cin >> n >> d >> x;
  rep(i,n) {
    int a;
    cin >> a;
    ans += (d-1)/a;
    ans++;
  }

  cout << ans + x << endl;
  return 0;

}