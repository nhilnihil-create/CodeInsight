#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  vector<int> T(4);
  for(int i=0; i<6; i++){
    int a;
    cin >> a;
    T.at(a-1)++;
  }
  int cnt=0;
  for(int i=0; i<4; i++){
    cnt=max(cnt, T.at(i));
  }
  if(cnt==2) cout << "YES" << endl;
  else cout << "NO" << endl;
}