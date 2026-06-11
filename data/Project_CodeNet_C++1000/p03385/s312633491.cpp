#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
  char S[4];
  cin>>S;
  if (S[0] != S[1] && S[1] != S[2] && S[2] != S[0]){
    cout<<"Yes";
  }else cout<<"No";
  return 0;
}