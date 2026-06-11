#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
int main() {
  ll r,d,x;
  cin >> r >> d >> x;
  vector<ll> x2(11);
  x2[0] = x;
  for(int i=1; i<11; i++){
    x2[i] = x2[i-1]*r - d;
    cout << x2[i] << endl;
  }
}
