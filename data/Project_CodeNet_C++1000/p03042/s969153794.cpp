#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  if((S[2]=='0'&&S[3]!='0')||(S[2]=='1'&&S[3]=='0')||(S[2]=='1'&&S[3]=='1')||(S[2]=='1'&&S[3]=='2')){
    if((S[0]=='0'&&S[1]!='0')||(S[0]=='1'&&S[1]=='0')||(S[0]=='1'&&S[1]=='1')||(S[0]=='1'&&S[1]=='2')){
      cout<<"AMBIGUOUS"<<endl;
    }
    else{
      cout<<"YYMM"<<endl;
    }
  }
  else{
    if(S[0]=='0'&&S[1]!='0'||S[0]=='1'&&S[1]=='0'||S[0]=='1'&&S[1]=='1'||S[0]=='1'&&S[1]=='2'){
      cout<<"MMYY"<<endl;
    }
    else{
      cout<<"NA"<<endl;
    }
  }
}