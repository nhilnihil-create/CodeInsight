#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int N;
  cin >> N;

  const int cake = 4;
  const int donut = 7;

  for (int i = 0; i <= 25; ++i) {
    for (int j = 0; j <= 15; ++j) {
      if (i * cake + j * donut == N) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  
  return 0;
}