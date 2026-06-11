#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int ans = 0;
  if (S.at(0) == '2') ans++;
  if (S.at(1) == '2') ans++;
  if (S.at(2) == '2') ans++;
  if (S.at(3) == '2') ans++;
  cout << ans << endl;
}