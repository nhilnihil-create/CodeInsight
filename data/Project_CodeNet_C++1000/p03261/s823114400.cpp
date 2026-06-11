#include <bits/stdc++.h>
using namespace std;



int main() {
  int N;
  cin>>N;
  vector<string> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  bool can=true;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(vec.at(i)==vec.at(j)){
        can=false;
        break;
      }
    }
    if(can) continue;
    else break;
  }
  
  for(int i=0;i<N-1;i++){
    int S=vec.at(i).size();
    if(vec.at(i).at(S-1)!=vec.at(i+1).at(0)){
      can=false;
      break;
    }
  }
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
       
 
}