#include<iostream>
using namespace std;
int main(){
  string S;
  cin>>S;
  int C_count=0;
  for(int i=0;i<S.length();i++){
    if(i==0&&S[i]!='A'){
      cout<<"WA"<<endl;
      return 0;
    }
    if(2<=i&&i<S.length()-1&&S[i]=='C'){
      C_count++;
      if(C_count>1){
        cout<<"WA"<<endl;
        return 0;
      }
    }
    if(S[i]!='A'&&S[i]!='C'){
      if('A'<=S[i]&&S[i]<='Z'){
        cout<<"WA"<<endl;
        return 0;
      }
    }
  }
  if(C_count==0){
    cout<<"WA"<<endl;
  }else{
    cout<<"AC"<<endl;
  }
  return 0;
}
