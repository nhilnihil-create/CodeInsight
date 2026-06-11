#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  string S;
  cin >> S;
  int cnt=0;
  for(int i=0; i<S.size(); i++){
    if(S.at(i)=='x') cnt++;
  }
  if(cnt<=7) cout << "YES" << endl;
  else cout << "NO" << endl;
}