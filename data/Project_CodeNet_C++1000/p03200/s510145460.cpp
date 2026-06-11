#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  long long ans = 0,w = 0;
  for(int i = 0 ; i < S.size() ; i++){
    if(S[i] == 'W'){
      ans +=i;
      w++;
    }
  }
  cout << ans-(w-1)*w/2 << endl;
}
