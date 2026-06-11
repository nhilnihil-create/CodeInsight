#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n, a, d;
  int ans = 100;//初期値
  cin >> n;//nこの整数がある

  rep(i, n) {//整数分ループする
    d = 0;
    cin >> a;//8
    while (a % 2 == 0) {//8を2でわってあまりが0なら
      a /= 2;//実際にaを2で割ってdをプラスする
      d++;
    }
    if (d < ans) ans = d;//もしdがansより小さければans = d;
  }
  cout << ans << endl;
}


