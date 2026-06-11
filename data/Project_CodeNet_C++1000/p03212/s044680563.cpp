#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,j,n3,n5,n7,ans=0;
  cin>>n;
  for(i=357;i<=min(n,77777753);i++){
    n3=0;n5=0;n7=0;
    j=i;
    while(j>0){
      if(j%10==3) n3++;
      else if(j%10==5) n5++;
      else if(j%10==7) n7++;
      else break;
      j/=10;
    }
    if(j==0&&n3>0&&n5>0&&n7>0) ans++;
  }
  for(i=333333357;i<=min(n,777777753);i++){
    n3=0;n5=0;n7=0;
    j=i;
    while(j>0){
      if(j%10==3) n3++;
      else if(j%10==5) n5++;
      else if(j%10==7) n7++;
      else break;
      j/=10;
    }
    if(j==0&&n3>0&&n5>0&&n7>0) ans++;
  }
  cout<<ans<<endl;
}