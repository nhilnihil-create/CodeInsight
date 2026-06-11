#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

int main(){
  vector<vector<ll>> c(3, vector<ll>(3));
  ll sum = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ll a;
      cin >> a;
      sum +=a;
      c[i][j] = a;
    }
  }
  bool check = false;
  for (int a1 = 0; a1 <= 100; a1++) {
    ll b1 = c[0][0] - a1;
    ll b2 = c[0][1] - a1;
    ll b3 = c[0][2] - a1;
    ll a2 = c[1][0] - b1;
    ll a3 = c[2][0] - b1;
    if(3*(a1+a2+a3+b1+b2+b3)==sum)check = true;
  }
  if(check)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}