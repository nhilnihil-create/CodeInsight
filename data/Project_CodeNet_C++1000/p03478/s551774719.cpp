#include<bits/stdc++.h>
using namespace std;
int sum(int x){
  int d1,d2,d3,d4,d5;
  d1=x%10;
  x/=10;
  d2=x%10;
  x/=10;
  d3=x%10;
  x/=10;
  d4=x%10;
  x/=10;
  d5=x%10;
  return d1+d2+d3+d4+d5;
}
int main(){
  int N,a,b;
  cin>>N>>a>>b;
  int ans=0;
  for(int i=0;i<=N;i++){
    if(sum(i)>=a&&sum(i)<=b){
      ans+=i;
    }
  }
  cout<<ans<<endl;
}
