#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
ll lucas[100]; 
int main() {
  int n;
  cin >> n;
  lucas[0] = 2;
  lucas[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    lucas[i] = lucas[i-1] + lucas[i-2];
  }
  cout << lucas[n] << endl;
    return 0;
}