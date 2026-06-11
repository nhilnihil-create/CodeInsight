#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;


int main(){
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int rn, gn;
  rn = n / r + 1;
  gn = n / g + 1;

  ll ans = 0;
  rep(i, rn){
    rep(j, gn){
      ll rg = n - (i * r + j * g);
      if (rg >= 0 && rg % b == 0) ans++;
    }
  }
  cout << ans << endl;
}
