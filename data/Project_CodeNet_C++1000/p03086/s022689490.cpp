

#include <bits/stdc++.h>

#define loop(s, e, i) for (int i = s; i < e; ++i)
#define print(s) cout << s << endl;
#define DIV 1000000007
#define ll = long long
using namespace std;

/*
浮動小数点の入力
cout << fixed << setprecision(9) << endl;
*/

int main() {
  string S;
  cin >> S;

  int score = 0;
  loop(0, S.size(), i) {
    loop(i, S.size(), j) {
      if (S[j] == 'A' || S[j] == 'G' || S[j] == 'C' || S[j] == 'T') {
        score = max(score, j-i+1);
        continue;
      }
      break;
    }
  }
  print(score);
}
