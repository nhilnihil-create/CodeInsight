#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int64_t D, G;
  cin >> D >> G;
  vector<vector<int64_t>> pc(D, vector<int64_t>(2));
  for (int i = 0; i < D; i++) {
    cin >> pc.at(i).at(0) >> pc.at(i).at(1);
  }
  int ans = 10000;
  for (int tmp = 0; tmp < (1 << D); tmp++) {
    bitset<10> s(tmp);
    int64_t memo = 0;
    int memo2 = 0;
    int M = 1;
    int M2 = 1;    
    int N = 0;
    for (int i = 0; i < D; i++) {
      if (s.test(i)) {
        memo += (i + 1) * 100 * pc.at(i).at(0) + pc.at(i).at(1);
        memo2 += pc.at(i).at(0);
      }
      else {
        M = M2;
        M = (i + 1) * 100;
        N = pc.at(i).at(0);
      }       
    }
    if (memo >= G) {
      ans = min(memo2, ans);
    }
    else {
      if (G - memo <= M * N) {
        if ((G - memo) % M == 0) {
          memo2 += (G - memo) / M;
        }
        else {
          memo2 += ((G - memo) / M) + 1;
        }
      }
      else {
        memo2 += N;
        if ((G - memo - M * N) % M2 == 0) {
          memo2 += (G - memo) / M2;
        }
        else {
          memo2 += ((G - memo - M * N) / M2) + 1;
        }
      }
      ans = min(memo2, ans);
    }
  }
  cout << ans << endl;
}
      
    