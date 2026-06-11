#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  int y=s.size();
  int a=0;
  for(int i=0;i<y;i++){
    char x=s[y-1];
    for(int j=0;j<y-1;j++){
      s[y-j-1]=s[y-j-2];
    }
    s[0]=x;
    if(s==t){
      a++;
    }
  }
  if(a>0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}