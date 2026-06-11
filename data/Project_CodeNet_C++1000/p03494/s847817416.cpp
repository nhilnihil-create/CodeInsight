#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int main() {
  int N, tmp, ttl = -1;
  int cnt = 0;
  cin >> N;
  rep(i, N) {
    cnt = 0;
    cin >> tmp;
    while(true) {
      if (tmp % 2 != 0) {
        break;
      } else {
        cnt += 1;
        tmp /= 2;
      }
    }
    if (ttl == -1 || cnt <= ttl) {
      ttl = cnt;
    }
  }
  cout << ttl << endl;
}
