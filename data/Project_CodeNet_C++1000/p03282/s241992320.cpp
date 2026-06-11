#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll int64_t
#define all(v) v.begin(), v.end()

int main() {

  string S;
  ll K;

  cin >> S >> K ;

  char ans;

  for(int i=0;;i++){
    if(S[i]=='1'){
      K--;
      if(K<=0){
        ans=S[i];
        break;
      }
    }

    else{
      ans=S[i];
      break;
    }

    
  }

 
  
  cout << ans << endl;
  
  return 0;
}