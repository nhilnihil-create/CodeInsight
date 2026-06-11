#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string S;
  cin>>S;
  
  int x=0;
  int y=0;
  int z=0;
  
  
  if(S[0]=='A'){
    x=1;
  }
  
  for(int i=2;i<=S.size()-2;i++){
    if(S[i]=='C'){
      y++;
    }
  }
  
  for(int i=0;i<S.size();i++){
    if(islower(S[i])){
      z++;
    }
  }
  
  if(x==1&&y==1&&z==S.size()-2){
    cout<<"AC"<<endl;
  }
  else{
    cout<<"WA"<<endl;
  }
}