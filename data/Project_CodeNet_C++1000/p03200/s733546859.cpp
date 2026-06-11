#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  int L = S.size();
  long ans = 0;
  int ct = 0;
  for(int i = 0; i < L; ++i){
    if(S[i] == 'W'){
      ans += i - ct;
      ++ct;
    }
  }
  cout << ans << '\n';
  
}
