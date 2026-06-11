#include <bits/stdc++.h>
using namespace std;
int main(){
  #define int long long
  int answer = 0;
  string S, FS = "";
  cin >> S;
  for(int i = 0; i < (int) S.size(); i++) {
    if(S.at(i) != 'x'){
      FS += S.at(i);
    }
  }
  for(int i = 0; i < (int) FS.size(); i++) {
    if(FS.at(i) != FS.at((int) FS.size() - i - 1)){
      cout << -1 << endl;
      return 0;
    }
  }
  int s = (int) S.size();
  for(int i = 0; i < (int) S.size(); i++) {
    if(S.at(i) != S.at((int) S.size() - i - 1)) {
      answer++;
      if(S.at(i) == 'x') {
        S.insert((int) S.size() - i, "x");
      }
      else {
        S.insert(i, "x");
      }
    }
  }
  cout << answer << endl;
}