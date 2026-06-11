#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int M = 1e7;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main(){
  int r,g,b,n;
  cin >> r >> g >> b >> n;

  int ans = 0;
  for (int x = 0; x <= 3000; x++){
    for(int y = 0; y <= 3000; y++){
      if((n - x*r - y*g) % b != 0) continue;
      int z = (n - x*r - y*g) / b;
      if(z >= 0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
