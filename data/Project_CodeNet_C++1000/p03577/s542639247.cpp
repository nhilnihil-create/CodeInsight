#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


int main() {
  
  string S;
  cin >> S;

  int num;
  for(int i = 0;i <= S.size()-8;i++) {
    if(S.substr(i,8) == "FESTIVAL") num = i;
  }
  
  for(int i = 0;i < num;i++) {
    cout << S.at(i);
  }
}