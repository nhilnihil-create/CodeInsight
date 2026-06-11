#include<bits/stdc++.h>
using namespace std;

int main(void){
  char S[4];
  int cnt = 0;
  cin >> S;
  for(int i = 0; i < 4; i++){
    if(S[i] == '+')
      cnt++;
    else if(S[i] == '-')
      cnt--;
  }
  cout << cnt << "\n";
  return 0;
}
