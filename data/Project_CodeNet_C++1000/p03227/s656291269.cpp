#include <bits/stdc++.h>
using namespace std;

int main(){

  string S; cin >> S;

  if(S.size()<3) cout << S << endl;
  else {
    reverse(S.begin(), S.end());
    cout << S << endl;
  }

}