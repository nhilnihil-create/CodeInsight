#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;
using Graph = vector<vector<int>>;

int main() {
  int a, b, k;
  cin >> a >> b >> k;

  for (int i = min(a, b); i >= i; i--) {
    if (a % i == 0 && b % i == 0) {
      k--;
      if (k == 0) {
        cout << i << endl;
        return 0;
      }
    }
  }
}