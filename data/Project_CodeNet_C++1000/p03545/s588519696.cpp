#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  char A, B, C, D;
  cin >> A >> B >> C >> D;
  for(int i = 0; i < (1 << 3); i++) {
    string ans_s = "";
    ans_s = ans_s + A;
    int ans_i = A - '0';
    if((i >> 0) & 1) {
      ans_i += B - '0';
      ans_s = ans_s + "+" + B;
    }
    else {
      ans_i -= B - '0';
      ans_s = ans_s + "-" + B;
    }
    if((i >> 1) & 1) {
      ans_i += C - '0';
      ans_s = ans_s + "+" + C;
    }
    else {
      ans_i -= C - '0';
      ans_s = ans_s + "-" + C;
    }
    if((i >> 2) & 1) {
      ans_i += D - '0';
      ans_s = ans_s + "+" + D;
    }
    else {
      ans_i -= D - '0';
      ans_s = ans_s + "-" + D;
    }
    if(ans_i == 7) {
      ans_s = ans_s + "=7";
      cout << ans_s << endl;
      break;
    }
  }

  return 0;
}
