#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main(){
  string S,T;
  cin>>T;
  S="AKIHABARA";
  int N,e,f,ans;
N=T.size();
  e=0;
  for(int i=0;i<100;i++){
    if(i==9||i==8){
      if(e==N||(e==N-1&&T[e]=='A')){
        break;
      }
      else{
        cout<<"NO"<<endl;
        return 0;
      }
    }
    if(e==N){
      cout<<"NO"<<endl;
      return 0;
    }
  if(T[e]==S[i]){
    e++;
    continue;
  }
    else if(S[i]=='A'){
      continue;
    }
    else{
      cout<<"NO"<<endl;
      return 0;
    }
  }
      cout<<"YES"<<endl;
}
