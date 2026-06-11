#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B;cin>>N>>A>>B;
  int ans=0;
  for(int i=1;i<=N;i++){
    int count=0;
    int X=i;
    while(X>0){
      count+=X%10;
      X/=10;
    }
    if(count>=A && count <=B) ans+=i;
  }
  cout<<ans<<endl;
}

