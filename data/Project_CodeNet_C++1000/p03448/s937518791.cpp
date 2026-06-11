#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int A, B, C, X;
  cin >> A >> B >> C >> X;

  int ans = 0;
  for(int i = 0; i <= A; i++){
    for(int j = 0; j <= B; j++){
      for(int k = 0; k <= C; k++){
        if (500 * i + 100 * j + 50 * k == X) ans ++;
      }
    }
  }
  cout << ans << endl;
}
