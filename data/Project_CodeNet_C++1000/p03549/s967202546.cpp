#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n,m;
  cin >> n >> m;
  int l = (n-m)*100 + m*1900;
  rep(i,m) {
    l *= 2;
  }
  cout << l << endl;
  return 0;
}