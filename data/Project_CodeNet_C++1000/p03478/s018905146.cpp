#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,A,B;
  cin>>N>>A>>B;
  
  int ans=0;
  
  
  for(int i=1;i<=N;i++){
    int num=0;
    int j=i;
    while(true){
      num+=j%10;
      j=j/10;
      if(j==0){
        break;
      }
    }
      if(num>=A&&num<=B){
        ans+=i;
      }
  }
  
  cout<<ans<<endl;
}