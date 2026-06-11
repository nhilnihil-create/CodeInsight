#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
//  cout << S << endl;
  
  for (int tmp=0; tmp<(1<<(S.size()-1)); tmp++) {
    bitset<3> bit_tmp(tmp);
//    cout << bit_tmp << endl;

    string s_result = "";
    s_result += S.at(0);
    int result = stoi(s_result);

    for (int cnt=1; cnt<S.size(); cnt++) {
      string S_n = "";
      S_n += S.at(cnt);
//      cout << S_n << endl;
      if( bit_tmp.test(cnt-1) ) {
        result += stoi(S_n);
        s_result += "+";
        s_result += S_n;
      } else {
        result -= stoi(S_n);
        s_result += "-";
        s_result += S_n;
      }
//      cout << result << endl; 
    }
    if (result == 7) {
      cout << s_result << "=7" << endl;
      return 0;
    }
  }

  return 0;
}