#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  int ans = s.at(0) - '0'; int ans1 = 0; 
  //cout << s.size() << endl;
  rep(bit, 1 << (s.size() - 1)){
    //cout << bit << endl;
    rep(i, s.size() - 1){
      //cout << i << endl;
      if(bit & (1<<i)) ans += (s.at(i + 1) -'0');
      else ans -= (s.at(i + 1) -'0');
    }
    if(ans == 7) {
      ans1 = bit;
      cout << s.at(0);
      rep(i, s.size() - 1){
        if(ans1 & (1<<i)) cout << "+" << s.at(i + 1);
        else cout << "-" << s.at(i + 1);
        if(i == s.size() - 2) cout << "=7" << endl;
      }
      break;
    }
    else ans = s.at(0) - '0';  
  }
}