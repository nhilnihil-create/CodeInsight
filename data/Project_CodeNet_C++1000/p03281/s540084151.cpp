#include<bits/stdc++.h>
using namespace std;
int countDivisor(int N){
  int ans=0;
  for(int i=1;i<=N;i++){
    if(N%i==0){
      ans++;
    }
  }
    return ans;
}
int main(){
  int N;
  cin>>N;
  int ans=0;
  for(int i=1;i<=N;i+=2){
    if(countDivisor(i)==8){
      ans++;
    }
  }
  cout<<ans<<endl;
}
