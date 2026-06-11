#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  string s;
  cin>>a>>b>>s;
  int at=0;
  for(int i=0;i<a;i++){
    if(!(s[i]>='0'&&s[i]<='9')){
      at++;
    }
  }
  for(int i=a+1;i<a+b+1;i++){
    if(!(s[i]>='0'&&s[i]<='9')){
      at++;
    }
  }
  if(s[a]!='-'){
    at++;
  }
  if(at>0) cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}
