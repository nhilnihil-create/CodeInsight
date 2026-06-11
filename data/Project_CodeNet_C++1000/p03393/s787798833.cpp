#include <bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  vector<long> data(26);
  for(int i = 0; i < S.size(); i++){
    data.at(S.at(i) - 'a')++;
  }
  if(S.size() == 26){
    for(int i = 25; i >= 0; i--){
      for(int j = S.at(i) - 'a' + 1; j < 26; j++){
        if(data.at(j) == 0){
          for(int k = 0; k < i; k++){
            cout << S.at(k);
          }
          cout << (char)('a' + j) << endl;
          return 0;
        }
      }
      data.at(S.at(i) - 'a')--;
    }
    cout << -1 << endl;
  } else {
    for(int i = 0; i < 26; i++){
      if(data.at(i) == 0){
        cout << S << ((char)('a' + i)) << endl;
        return 0;
      }
    }
  }
  return 0;
}