#include<bits/stdc++.h>
using namespace std;

int main(void){
  char S[3];
  int value = 700;
  cin >> S;
  for(int i = 0; i < 3; i++){
    if(S[i] == 'o')
      value += 100;
  }
  cout << value << "\n";
  return 0;
}
