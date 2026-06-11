#include <bits/stdc++.h>
using namespace std;

int main(){
  int dig[3];
  for(int i=0; i<3; ++i) cin >> dig[i];
  int dig2[3];
  string ans = "Yes";
  for(int i=0; i<2; ++i){
    for(int j=0; j<3; ++j) cin >> dig2[j];
    if(dig2[0] -dig[0] != dig2[1] -dig[1]){
      ans = "No";
    }
    if(dig2[0] -dig[0] != dig2[2] -dig[2]){
      ans = "No";
    }
  }
  cout << ans << endl;
}