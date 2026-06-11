#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  int X;
  cin >> X;
  int ans1 = 1;
  int ans2 = 1;
  for(int b = 2; b<= X; b++){
    for(int p = 2; pow(b,p)<= X; p++){
      ans1 = pow(b,p);
    }
    ans2 = max(ans2,ans1);
  }
  cout << ans2 << endl;
}      
    