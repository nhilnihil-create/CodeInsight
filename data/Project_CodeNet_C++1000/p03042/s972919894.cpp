#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  string S;
  cin>>S;
  bool YYMM=false,MMYY=false;
  if(S[0]=='0'&&S[1]!='0'){
      MMYY=true;
  }
  else if(S[0]=='1'&&S[1]<='2'){
      MMYY=true;
  }
  
  if(S[2]=='0'&&S[3]!='0'){
      YYMM=true;
  }
  else if(S[2]=='1'&&S[3]<='2'){
      YYMM=true;
  }
  
  if(MMYY==true&&YYMM==false){
      cout<<"MMYY"<<endl;
  }
  else if(MMYY==false&&YYMM==true){
      cout<<"YYMM"<<endl;
  }
  else if(MMYY==true&&YYMM==true){
      cout<<"AMBIGUOUS"<<endl;
  }
  else if(MMYY==false&&YYMM==false){
      cout<<"NA"<<endl;
  }
  
}