#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,ans=0,i;
  int64_t K;
 
  cin>>A>>B>>K;
  if(A>B)
    i=B;
  else
    i=A;
  while(1){
    if(A%i==0&&B%i==0)
      ans++;
    if(ans==K){
      cout<<i<<endl;
      break;
    }
    i--;
  }
}
