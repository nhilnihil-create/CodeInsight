#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int k;
  cin >> k;

  if (k % 2 == 0) cout << (k / 2) * (k / 2) << endl;
  else cout << (k / 2 + 1) * (k / 2) << endl;
}
