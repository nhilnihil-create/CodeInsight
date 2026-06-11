#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,X;
  cin>>N>>X;
  vector<int> m(N);
  int sum=0;
  for(int i=0;i<N;i++){
    cin>>m.at(i);
    sum+=m.at(i);
  }
  
  sort(m.begin(),m.end());
  
  int ans=N;
  
  while(true){
    if(X>=sum+m.at(0)){
      ans++;
      sum+=m.at(0);
    }
    else{
      break;
    }
  }
  cout<<ans<<endl;
}