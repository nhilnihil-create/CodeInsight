#include<bits/stdc++.h>
using namespace std;
int main(){
  long long  X, Y;
  cin >> X >> Y;
  int ans = -1;
  
  if(X %Y == 0){
   ans = -1;
  }
  else{
    int i=1;
   while(X*i < 10000000000000000){
    if(X*i %Y != 0){
      ans = X*i;
      break;
    }
    i++;
   }
  }
  cout << ans << endl;
}  