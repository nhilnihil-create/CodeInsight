#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int k, a, b;
  cin >> k >> a >> b;
  ll ans = 1;
  while (k>0) {
    if(b-a<2||ans<a||k<2) {
      ans++;
      k--;
    }
    else {
      ans += b-a;
      k -= 2;
    }
  }
  
  cout << ans << endl;
}
