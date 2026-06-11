#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int n, x;
  vi m(110);
  cin >> n >> x;
  int sum = 0;
  int min_m = 20000;
  rep(i, n) {
    cin >> m[i];
    sum += m[i];
    if (min_m > m[i]) min_m = m[i];
  }

  int leftovers = x - sum;
  int cnt = 0;
  if (leftovers != 0) {
    while(leftovers >= 0) {
      cnt++;
      leftovers -= min_m;
    }
    cnt--;
  }

  cout << n+cnt << endl;


  return 0;
}