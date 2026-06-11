#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int ans=1;
  for(int i=1;i<N;i++){
    if(i*i<=N&&(i+1)*(i+1)>N){
      ans=i;
      break;
    }
  }
  cout<<ans*ans<<endl;
}
