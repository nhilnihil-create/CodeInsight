#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin >>N;
  
  vector <string> s(N);
  
  for(int i=0;i<N;i++){
    cin >> s.at(i);
  }
  
  cin >>M;
  
  vector <string> t(M);
  
  for(int i=0;i<M;i++){
    cin >> t.at(i);
  }
  
  int ans=0;
  
  for(int i=0;i<N;i++){
    int x=0;
    for(int j=0;j<N;j++){
      if(s.at(i)==s.at(j)){
        x++;
      }
    }
    
    for(int j=0;j<M;j++){
      if(s.at(i)==t.at(j)){
        x--;
      }
    }
    
    if(x>ans)ans=x;
  }
  
  cout<<ans<<endl;
  
}