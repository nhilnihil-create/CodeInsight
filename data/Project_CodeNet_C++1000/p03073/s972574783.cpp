#include<bits/stdc++.h>
using namespace std;
int main(){
  string S; cin >> S;
  string ans_S;
  ans_S += S.at(0);
  for(int i = 1; i < S.size(); i++){
    if(ans_S.at(i - 1) == '1')
      ans_S += '0';
    else
      ans_S += '1';
  }
  int cnt = 0;
  for(int i = 0; i < S.size(); i++){
    if(ans_S.at(i) != S.at(i)) cnt++;
  }
  
  cout << cnt << endl;
}
      