#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;

int main() {
    char num[4]={0};
    for (int i = 0; i < 4; i++) cin >> num[i];

    for (int bit = 0; bit < (1 << 4); bit++) {
      ll sum = num[0]-'0';
      vector<char> hugou;
      for (int i = 1; i < 4; i++) {
        if (bit & (1 << i)) {
          sum += num[i] - '0';
          hugou.push_back('+');
        } else {
          sum -= num[i] - '0';
          hugou.push_back('-');
        }
      }
        if (sum == 7) {
          cout << num[0] << hugou[0] << num[1] << hugou[1] << num[2] << hugou[2]
               << num[3] << "=7" << endl;
          break;
        }
    }
    return 0;
}