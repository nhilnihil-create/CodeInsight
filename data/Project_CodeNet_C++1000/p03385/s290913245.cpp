#include<bits/stdc++.h>
using namespace std;
int main(){
  string x;
  cin>>x;
  int a,b,c;
  a=0;b=0;c=0;
  for(int i=0;i<3;i++){
    if(x[i]=='a'){
      a+=1;
    }else if(x[i]=='b'){
      b+=1;
    }else if(x[i]=='c'){
      c+=1;
    }
  }
  if(a==1&&b==1&&c==1){
    cout<<"Yes";
  }else{
    cout<<"No";
  }
}