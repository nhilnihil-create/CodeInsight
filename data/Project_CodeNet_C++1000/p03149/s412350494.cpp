#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
  vector<int> vec(4);
  rep(i, 4) cin >> vec[i];
  sort(vec.begin(), vec.end());
  if (vec[0] == 1 && vec[1] == 4 && vec[2] == 7 && vec[3] == 9) cout << "YES" << endl;
  else cout << "NO" << endl;
}
