#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int ans = 700;
  for (int i=0;i<3;i++){
    if (S.at(i) == 'o') ans += 100;
    else if (S.at(i) == 'x') continue;
  }
  cout << ans << endl;
}