#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  bool a=true;
  char C='a';
  vector<string> W(N);
  for(int i=0;i<N;i++){
    cin >> W.at(i);
    if(i!=0){
      if(W.at(i).at(0)!=C){
        a=false;
      }  
    }
   C=W.at(i).at(W.at(i).size()-1);
  }
  sort(W.begin(),W.end());
  for(int i=0;i<N-1;i++){
    if(W.at(i)==W.at(i+1)){
      a=false;
    }
  }
  if(a){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
    
    