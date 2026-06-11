#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  string S;
  cin>>A>>B>>S;
  for(int i=0;i<A+B+1;i++){
    if(S[i]=='-'){
      if(i!=A){
        cout<<"No"<<endl;
        return 0;
      }
    }else if(i==A){
        cout<<"No"<<endl;
        return 0;
      }
  }
  cout<<"Yes"<<endl;
}