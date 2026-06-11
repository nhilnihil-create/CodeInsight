

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
  int N;
  cin >> N;

  int results = 0;
  loop(1, N+1, n) {
    if (n%2 == 0) continue;

    int count = 0;
    int duplicated = 0;
    for (int i=1; i*i<=n; i++) {
      if (n%i == 0) {
        count++;
      }
      if (i*i == n) {
        duplicated = 1;
      }
    }
    count *= 2;
    count -= duplicated;
    if (count == 8) {
      results++;
    }
  }
  print(results);

}
