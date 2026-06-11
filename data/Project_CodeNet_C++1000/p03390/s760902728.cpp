#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 解説を証明するのが大変(なにこれ)(でもすき)
// 上からガッツリ抑えて, それを構築可能であることが言える, すごい

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) {
    ll a, b; cin >> a >> b;
    if(a > b) swap(a, b);
    if(a == b) {
      cout << 2 * (a - 1) << endl;
    } else if (a + 1 == b) {
      cout << 2 * (a - 1) << endl;
    } else {
      ll c = sqrt(a * b);
      if(c * c == a * b) c--;
      if(c * (c + 1) < a * b) {
        cout << 2 * c - 1 << endl;
      } else {
        cout << 2 * c - 2 << endl;
      }
    }
  }
}

