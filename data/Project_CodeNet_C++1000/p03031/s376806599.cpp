


#include <bits/stdc++.h>

#define loop(s, e, i) for (int i = s; i < e; ++i)
#define print(s) cout << s << endl;
#define DIV 1000000007
#define ll long long
using namespace std;

/*
浮動小数点の入力
cout << fixed << setprecision(9) << endl;
*/

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(M, vector<int>(N));
  loop(0, M, i) {
    int K;
    cin >> K;
    loop(0, K, j) {
      int tmp;
      cin >> tmp;
      tmp--;
      A[i][tmp] = 1;
    }
  }
  vector<int> P(M);
  loop(0, M, i) cin >> P[i];

  int c = 0;
  for(int bit=0; bit<(1<<N); bit++) {
    vector<int> COUNT(M);
    for (int i=0; i<N; i++) {
      if (!(bit & 1<<i)) continue;
      loop(0, M, j) {
        if (A[j][i] == 1) COUNT[j]++;
      } 
    }
    bool result = true;
    loop(0, M, i) {
      if (COUNT[i]%2 != P[i]) {
        result = false;
        break;
      }
    }
    if (result) {
      c++;
    }
  }
  print(c);
}
