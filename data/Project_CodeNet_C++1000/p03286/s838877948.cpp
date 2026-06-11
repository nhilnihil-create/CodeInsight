#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N;
    cin >> N;
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll base = 1;
    string S;
    while (N != 0) {
      if (N % (base * 2) == 0) S.push_back('0');
      else { 
          S.push_back('1');
          N -= base;
      }
      base *= -2;
    }
    reverse(S.begin(), S.end());
    cout << S << endl;
}
