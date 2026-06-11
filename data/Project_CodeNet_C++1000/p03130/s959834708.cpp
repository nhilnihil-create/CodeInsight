#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
  vector<int> cnt(4);
  int tmp;
  rep(i, 6) {
    cin >> tmp;
    tmp--;
    cnt[tmp]++;
  }
  rep(i, 4) {
    if (cnt[i] == 3) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
    
