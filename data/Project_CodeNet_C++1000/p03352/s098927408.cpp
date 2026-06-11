#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;


int main() {
  int x;
  cin >> x;
  int ans = 1;
  for(int b = 1; b*b <= x; b++){
    for(int p = 2; p <= 10; p++){
      int tmp = pow(b, p);
      if(tmp <= x) ans = max(ans, tmp);
    }
  }
  
  cout << ans << endl;

}


