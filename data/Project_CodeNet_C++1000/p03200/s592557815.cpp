#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;



int main() {
  string moji;
  cin >> moji;
  ll ans = 0;
  

  int wnumber = 0; ///左から見て何番目のWか
  rep(i, moji.length()){
    if (moji[i] == 'W') {
      ans += i - wnumber;
      wnumber ++;
      }
    }
    cout << ans << endl;
  }
