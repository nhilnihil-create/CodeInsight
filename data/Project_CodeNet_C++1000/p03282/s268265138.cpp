#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  long long K;
  cin >> S >> K;
  
  char ans;
  int count =0;
  for(int i=0; i<S.size(); i++){
    if(S.at(i)=='1')count ++;
    else break;
  }
  
  if(K<=count)ans ='1';
  else ans = S.at(count);
  
  cout << ans << endl;
    
}
