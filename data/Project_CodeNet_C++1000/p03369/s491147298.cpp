#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    string s;
    cin >> s;
    int res=700;
    rep(i, s.size()) {
      if (s[i] == 'o') res += 100;
    }
    cout << res << endl;
}
