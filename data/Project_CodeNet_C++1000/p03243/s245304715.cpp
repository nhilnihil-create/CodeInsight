#include <bits/stdc++.h>
using namespace std; 
int main(){
  int n;
  cin >> n;
  int i=1;
  while(1){
    int ans=0;
    ans=i*100+i*10+i;
    if(ans-n>=0){
      cout << ans;
      break;
    }
    i++;
  }
}
    
  
