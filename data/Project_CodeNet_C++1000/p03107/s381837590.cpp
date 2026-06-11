#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string S;
  cin >> S;

  int cnt_red = 0, cnt_blue = 0;
  for(int i = 0; i < S.size(); i++) {
    if(S[i] == '0') cnt_red++;
    else cnt_blue++;
  }
  cout << min(cnt_red, cnt_blue) * 2 << endl;

  return 0;
}
