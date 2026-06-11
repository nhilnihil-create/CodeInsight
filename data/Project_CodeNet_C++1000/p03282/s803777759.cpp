#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
 
  string S;
  ll K,index=0;
  cin >> S >> K;
  
  for(int i=0;i<S.size();i++){
      if(S[i] =='1')index++;
      else break;
  }
  
  if(K <= index) cout << 1 << endl;
  else cout << S[index] << endl;
  
}