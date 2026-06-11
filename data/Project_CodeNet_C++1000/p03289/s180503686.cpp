#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  bool flag1=false;
  bool flag2=false;
  bool flag3_=false;
  
  if (S[0]=='A'){
    flag1=true;
    S.erase(0,1);
  }
  int count=0;
  int x;
  for (int i=1; i<S.size()-1; i++){
    if (S[i]=='C'){
      count++;
      x=i;
    }
  }
  if (count==1){
    flag2=true;
  }
  if (flag2){
    S.erase(x,1);
  }
  
  for (int c : S){
    if (isupper(c)){
      flag3_=true;
    }
  }
  if (flag1*flag2*(!flag3_)){
    cout<<"AC"<<endl;
  }else{
    cout<<"WA"<<endl;
  }
}