#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;cin>>s;
  bool flag=true;
  for(int i=1;i<(int)s.size();i++)if(s[i]!='9'){
    flag=false;
    break;
  }
  cout<<9*(int)(s.size()-1)+(int)(s[0]-'0')-(flag?0:1)<<endl;
  return 0;
}