#include<bits/stdc++.h>
using namespace std;


int main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  
  long long ans = A*X+B*Y;
  for(int i=0;i<=100000;i++){
    long long work = A*max(0,X-i)+B*max(0,Y-i)+2*C*i;
    ans = min(ans,work);
  }
  
  cout << ans << endl;
  return 0;
}