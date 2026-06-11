#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b,k;
  cin>>a>>b>>k;
  int m=min(a,b);
  int count=0;
  int ans;
  for(int i=m;i>=1;i--){
    if(a%i==0 && b%i==0){
      count++;
      if(count==k){
        ans=i;
        break;
      }
    }
  }
  cout<<ans<<endl;
}