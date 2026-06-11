#include<iostream>
using namespace std;
int main(void){
  string s;
  cin>>s;
  int ans=700;
  if(s[0]=='o'){
    ans+=100;
  }
  if(s[1]=='o'){
    ans+=100;
  }
  if(s[2]=='o'){
    ans+=100;
  }
  printf("%d\n",ans);
  return 0;
}