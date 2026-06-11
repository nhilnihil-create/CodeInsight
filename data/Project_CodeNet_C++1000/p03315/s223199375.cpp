#include <bits/stdc++.h>
using namespace std;

int main() {
  char S;
  int ans=0;

  for(int i=0; i<4; i++){
    cin >> S;
    if(S=='+'){
      ans++;
    }
    else{
      ans--;
    }
  }

    cout << ans << endl;
  
return 0;  
}