#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int N;
  int ans=0;
  bool a=true;
  cin>>N;
  vector<int> test(N);
  for(int i=0;i<N;i++){
  cin>>test.at(i);
  }
 while(a){
  for(int i=0;i<N;i++){
  if(test.at(i)%2==1){
  a=false;
  }
  }
  if(a){
  
    for(int i=0;i<N;i++){
  test.at(i)=test.at(i)/2;}
    ans++;
    
  }
   
 }
  cout<<ans<<endl;
}