#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int cnt=0;
  int endA=0;
  int startB=0;
  int flag=0;
  string S;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>S;
    for(int j=0;j<S.length()-1;j++){
      if((S.at(j)=='A')&&(S.at(j+1)=='B')){
        cnt++;
      }
    }
    if((S.at(0)=='B')&&(S.at(S.length()-1)=='A')){
      flag++;
    }
    else if(S.at(0)=='B'){
      startB++;
    }
    else if(S.at(S.length()-1)=='A'){
      endA++;
    }

  }
  if(flag==0){
    cout<<cnt+min(startB,endA)<<endl;
    return 0;
  }
  if(startB+endA==0){
    cout<<cnt+flag-1<<endl;
    return 0;
  }
  cout<<cnt+flag+min(startB,endA)<<endl;
  return 0;
}
