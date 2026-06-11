#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  string s;
  ll k;
  cin >> s >> k;
  REP(i,k){
    if(s[i] != '1'){
      cout << s[i] << endl;
      return 0;
    }
  }
  cout << 1 << endl;
}
