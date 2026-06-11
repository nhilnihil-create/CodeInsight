#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string S;
  cin >> S;

  int cnt_black = 0, cnt_wite = 0, cnt_even = 0, cnt_odd = 0;
  for(int i = 0; i < S.size(); i++) {
    if(i % 2 == 0) {
      cnt_even++;
      if(S[i] == '0') cnt_black++;
    }
    else {
      cnt_odd++;
      if(S[i] == '1') cnt_wite++;
    }
  }

  cout << min((cnt_black + cnt_wite), ((cnt_even - cnt_black) + (cnt_odd - cnt_wite))) << endl;
  return 0;
}
