#include<bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin >> X;
  int ans=1;
  for(int i=2;i<X+1;i++){
    int P=i*i;
    for(int j=2;;j++){
      if(P>X){
        break;
      }
      ans=max(P,ans);
      P*=i;
    }
  }
  cout << ans << endl;
}