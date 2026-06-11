#include<bits/stdc++.h>
using namespace std;

int main(void){
  char S[3];
  cin >> S;
  if(S[0] == S[1] || S[1] == S[2] || S[0] == S[2])
    cout << "No" << "\n";
  else
    cout << "Yes" << "\n";
  return 0;
}
