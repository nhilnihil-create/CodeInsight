#include <bits/stdc++.h>
using namespace std;

int ans=0;
int main(){
  int A,B;
  cin>>A>>B;
  for (A;A<=B;A++){
    int AA=A;
    if(AA%10==AA/10000){
      AA-=(AA/10000)*10000;
      AA/=10;
      if(AA%10==AA/100){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}