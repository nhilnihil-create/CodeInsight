#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X;
  cin >> A>>B>>C>>X;
  int Y;
  Y=X/50;
  int ans=0;
  for (int i=0;i<=A;i++){
    for(int j=0;j<=B;j++){
      for(int k=0;k<=C;k++){
        if(i*10+j*2+k==Y){
          ans++;
        }
      }
    }
  }
  cout << ans <<endl;
  
    
  
  
}