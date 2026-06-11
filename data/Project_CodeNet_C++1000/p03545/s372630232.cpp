#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  for(int b=0;b<(1<<3);++b){
    int ans = S[0] - '0';
    for(int i=1;i<4;++i){
      if(b & (1<<(i-1))){
        ans += S[i] - '0';
      }else{
        ans -= S[i] - '0';
      }
    }
    if (ans == 7){
      for(int i=0;i<3;++i){
        cout << S[i];
        if(b & (1<<i)){
          cout << '+';
        }else{
          cout << '-';
        }
      }
      cout << S[3] << "=7" << endl;
      return 0;
    }
  }



}
