#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  char c;
  int ans = 0;

  cin >> S;
  c = S.at(0);

  for(int i=1;i<S.size();++i){
    if(S.at(i) == c){
      if(S.at(i) == '1'){
        S.at(i) = '0';
        ans++;
      }else{
        S.at(i) = '1';
        ans++;
      }
    }
    c = S.at(i);
  }
  cout << ans << endl;
  return 0;
}
