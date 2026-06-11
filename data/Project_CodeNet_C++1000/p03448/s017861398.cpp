#include <bits/stdc++.h>
using namespace std;

int main(void){
    
  int A,B,C,X,ans=0;
  cin >> A >> B >> C >> X;
  
  for(int i=0;i<=A;i++){
      for(int j=0;j<=B;j++){
          for(int l=0;l<=C;l++){
              if(500 * i + 100 * j + 50 * l == X) ans++;
          }
      }
  }
  
  cout << ans << endl;
}