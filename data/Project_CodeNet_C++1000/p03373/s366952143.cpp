#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = INF;
  for (int i = 0; i <= 100000; i++){
    int tmp = i * 2 * C;
    if (i < X){
      tmp += (X - i) * A;
    }
    if (i < Y){
      tmp += (Y - i) * B;
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}