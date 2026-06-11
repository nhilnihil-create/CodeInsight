#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
 string s;
  cin>>s;
  int a=s.size(),ans1=0,ans2=0,ans3=0,count=0;
  for(int i=2;i<a-1;i++){
if(s[i]=='C'){
  ans1=1;
  count+=1;
}
  }
  if(count!=1) ans1=0;
  
  if(s[0]=='A') ans2=1;
  for(int i=0;i<a;i++){
    if(s[i]!='A'&&s[i]!='C'&&s[i]>='B'&&s[i]<='Z') ans3=1;
  }
  if(ans1==1&&ans2==1&&ans3==0) cout<<"AC"<<endl;
  else cout<<"WA"<<endl;
  return 0;
}
