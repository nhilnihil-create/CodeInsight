#include <bits/stdc++.h>
using namespace std;
int check(char x){
  if(x=='A' || x=='T' || x=='C' || x=='G'){
    return 1;
  }
  else{
  return 0;
  }
}

int main(){
  string S;
  cin>>S;
  int count_inside=0,count_outside=0,j=0;
  for(int i=0;i<S.size();i++){
    j=i;
    count_inside=0;
    while(check(S.at(j))==1){
      count_inside++;
      j++;
      if(j==S.size()){
      break;
      }
    }
    count_outside=max(count_inside,count_outside);
  }
  cout<<count_outside<<endl;
}
