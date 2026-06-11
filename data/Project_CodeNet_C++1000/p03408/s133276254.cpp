#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int G, L;
  cin >> G;
  vector<string> vecG(G);
  rep(i, G) {
    cin >> vecG.at(i);
  }
  cin >> L;
  vector<string> vecL(L);
  rep(i, L) {
    cin >> vecL.at(i);
  }
  int MA = 0;
  int co = 0;
  rep(i, G) {
    rep(j, G) {
      if(vecG.at(i) == vecG.at(j)) {
        co++;
      }
    }
    rep(j, L) {
      if(vecL.at(j) == vecG.at(i)) {
        co--;
      }
    }
    MA = max(MA, co);
    co = 0;
  }
  cout << MA << endl;
}