#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  vector<string> W(N);
  for(int i=0;i<N;i++) cin>>W.at(i);
  bool shirit=true;
  for(int i=0;i<N;i++){
    if(shirit){
      for(int j=i+1;j<N;j++){
        if(W.at(i)==W.at(j)){
          shirit=false;
          break;
        }
      }
    }
  }
  if(shirit){
    for(int i=0;i<N-1;i++){
      int l=W.at(i).size();
      if(W.at(i).at(l-1)!=W.at(i+1).at(0)){
        shirit=false;
        break;
      }
    }
  }
  if(shirit) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
    