#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x;
  int ans=0;
  
  cin >> a >> b >> c >>x;
  
  for(int i=0;i<=a&&x/500+1;i++){
    for(int j=0;j<=b&&x/100+1;j++){
      for(int k=0;k<=c&&k/50+1;k++){
        if(500*i+100*j+50*k==x){
          ans++;
        }
      }
    }
  }
  
  cout << ans << endl;
}