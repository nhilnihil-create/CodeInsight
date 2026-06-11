#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string A,B,C;
  cin>>N>>A>>B>>C;
  int ans=0;
  for(int i=0;i<N;i++){
    int a=A.at(i);
    int b=B.at(i);
    int c=C.at(i);
    if(a==b&&b==c){
      continue;
    }else if(a==b||b==c||c==a){
      ans+=1;
    }else{
      ans+=2;
    }
  }
  cout<<ans<<endl;
}