#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  string s;
  cin>>s;
  int g=0;
  int f=0;
  int h=0;
  if(s[0]=='A'){
    g=1;
  }
  for(int i=0;i<s.length();i++){
    if(s[i]>=92){
      h++;
    }
  }
  for(int i=2;i<s.length()-1;i++){
    if(s[i]=='C'){
      f=1;
      i=s.length();
    }
  }
  if(f && h==s.length()-2 && g){
    cout<<"AC";
  }else{
    cout<<"WA";
  }
  
  
}