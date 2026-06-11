#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll X, Y;
    cin >> X >> Y;
    ll c = 0;
    while (X <= Y) {
      X *= 2;
      c++;
    }
    cout << c << endl;
}
