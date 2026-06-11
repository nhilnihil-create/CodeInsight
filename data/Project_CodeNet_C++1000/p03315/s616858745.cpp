#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int ans = -4;
  if (S.at(0) == '+') ans += 2;
  if (S.at(1) == '+') ans += 2;
  if (S.at(2) == '+') ans += 2;
  if (S.at(3) == '+') ans += 2;
  cout << ans << endl;
}