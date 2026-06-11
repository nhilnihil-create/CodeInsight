#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    string s;
    cin >> s;
    int K;
    cin >> K;
    set<string> m;
    rep(i,s.size()) {
      for (int j = 1; j <= K; j++) {
          m.insert(s.substr(i,j));
      }
    }
    cout << *next(m.begin(), K-1) << endl;
}
