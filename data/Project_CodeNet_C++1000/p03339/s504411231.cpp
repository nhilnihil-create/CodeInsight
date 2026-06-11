#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int K;
    cin >> K;
    string s;
    cin >> s;
    vector<int> V(K);
    int west = 0;
    int east = 0;
    for (int i = 1; i < s.size(); i++) {
      if (s[i -1] == 'W') {
        west++;
      }
      V[i] = west;
    }
    for (int i = s.size() - 2; i >= 0; i--) {
      if (s[i + 1] == 'E') east++;
      V[i] += east;
    }
    sort(V.begin(), V.end());
    cout << V[0] << endl;
}
