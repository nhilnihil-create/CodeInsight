#include <bits/stdc++.h>
using namespace std;
 
int main(){ 
  
 int N;
 cin>>N;
 
  vector<int>d(N);
  
  for(int i=0;i<N;i++){
    cin>>d.at(i);
  }
  
  int ans=0;
  
  for(int j=0;j<101;j++){
    for(int i=0;i<N;i++){
      if(d.at(i)==j){
        ans++;
        break;
      }
    }
  }
  cout<<ans<<endl;
}
   