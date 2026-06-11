#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
  int N, B[3];
  cin >> N >> B[0] >> B[1] >> B[2];
  vector <int>l(N);
  for  (int i = 0; i < N; i++) cin >> l[i];

  unsigned int total_cost = 3000; //temp max
  for (unsigned int i = 0; i < pow(4, N);  i++) {
    vector <unsigned int> usage(N); // 0:not use, 1:for A, 2: for B, 3: for C
    unsigned int wk = i;
    unsigned int not_bamboo_check = 0x0;
    for (int j = 0; j < N; j++) {
      usage[j] = wk & 0x3;
      wk >>= 2;
      not_bamboo_check |= (1 << usage[j]);
    }
    // A, B, Cそれぞれについて。最低1つは竹材が欲しい
    if ((not_bamboo_check&0xE) != 0x0E) continue;

    unsigned int cost = 0;
    for (int k = 0; k < 3; k++) { // for A, B, C
      int bamboo_len = 0;
      for (int j = 0; j < N; j++) {
        if (usage[j]==(k+1)) {
          if (bamboo_len) {cost += 10;} // 2本以上結合する場合、MP10
          bamboo_len += l[j];
        }
      }
      cost += abs(bamboo_len - B[k]);
    }
    total_cost = min(total_cost, cost);
  }
  cout << total_cost << endl;
  return 0;
}
