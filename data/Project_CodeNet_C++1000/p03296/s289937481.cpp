#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const long long MOD = 1000000007;

typedef long long ll;

int main(void) {
  int n;
  int a[200];
  cin >> n;
  rep(i, n) cin >> a[i];

  int k = 0, ans = 0;
  while (k < n) {
    int key = k;
    while (k < n && a[key] == a[k]) k++;
    ans += (k - key) / 2;
  }

  cout << ans << endl;

  return 0;
}
