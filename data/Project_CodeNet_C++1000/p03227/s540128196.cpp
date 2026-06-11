#include<iostream>
#include<string>
using namespace std;
int main() {
  string S;
  cin >> S;
  if(S.size() == 2) cout << S;
  else{
    for(int i=0;i<3;i++) cout << S[2-i];
  }
  return 0;
}