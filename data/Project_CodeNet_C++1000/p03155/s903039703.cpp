#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  ll n, h, w;
  cin >> n >> h >> w;
  cout << (n-h+1) * (n-w+1) << endl; 
  return 0;
}
