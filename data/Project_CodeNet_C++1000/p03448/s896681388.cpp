#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A, B, C, X;
  cin >> A >> B >> C >> X;
  int c = 0;
  rep(i, A) {
    rep(j, B) {
      rep(k, C) {
        if(500 * i + 100 * j + 50 * k == X) {
          c++;
        }
      }
    }
  }
  cout << c << endl;
}