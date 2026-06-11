#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD =1e9+7;
using ll=long long;

int r, g, b;
int n, R, G, B;
int ans;
int main(){
  cin >> R >> G >> B >> n;
  for(int r = 0; r*R <= n; r++){
    for(int g = 0; r*R + g*G <= n; g++){
      if((n - (r*R + g*G)) % B == 0) ans ++;
    }
  }
  cout << ans << endl;
}
