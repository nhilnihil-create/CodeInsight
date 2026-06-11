#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='A'){
      cout<<"T"<<flush;
    }else if(s[i]=='T'){
      cout<<"A"<<flush;
    }else if(s[i]=='G'){
      cout<<"C"<<endl;
    }else{
      cout<<"G"<<endl;
    }
  }
  cout<<endl;
}