#include <bits/stdc++.h>
using namespace std;

bool check(char c){
  bool ans = false;
  if(c == '0') ans = true;
  if(c == '1') ans = true;
  if(c == '2') ans = true;
  if(c == '3') ans = true;
  if(c == '4') ans = true;
  if(c == '5') ans = true;
  if(c == '6') ans = true;
  if(c == '7') ans = true;
  if(c == '8') ans = true;
  if(c == '9') ans = true;
  return ans;
}

int main(){
  int A, B;
  string S, ans = "Yes";
  cin >> A >> B >> S;
  for(int i = 0; i < A; i++){
    if(check(S.at(i)) == false) ans ="No";
  }
  if(S.at(A) != '-') ans = "No";
  for(int i = A + 1; i < A + B + 1; i++){
    if(check(S.at(i)) == false) ans ="No";
  }
  cout << ans << endl;
  return 0;
}