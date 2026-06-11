#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  string S; cin >> S;
  if(S[5] == '0'){
    if(S[6] == '1' || S[6] == '2' || S[6] == '3' || S[6] == '4'){
      cout << "Heisei";
      return 0;
    }
  }
  cout << "TBD";
}