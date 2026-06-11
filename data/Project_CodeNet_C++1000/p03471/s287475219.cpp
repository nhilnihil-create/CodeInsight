#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;


int main() {

  int m[3];
  m[0] = 10;
  m[1] = 5;
  m[2] = 1;

  int N,Y;
  cin >> N >> Y;
  Y/= 1000;
  rep(i,N + 1){
    rep(j,N + 1 - i){
      int k = (N - i - j);
      int y = i * m[0] + j * m[1] + m[2] * k;
      if(y == Y ) {
        cout << i << " " << j << " " << k << endl;
        return 0;
      } 
    }
  }

  cout << -1 << " " << -1 << " " << -1 << endl;

	return 0;
}

