#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ctoi(char c){
  if(c>='0'&&c<='9'){
    return c-'0';
  }
  return 0;
}

int main(){
  string s;
  cin>>s;
  for(int i=1;i<s.size();i++){
    if(ctoi(s[i])!=9){
      goto skip;
    }
  }
  cout<<ctoi(s[0])+9*(s.size()-1)<<endl;
  return 0;
  skip:
  cout<<ctoi(s[0])+9*(s.size()-1)-1<<endl;
  return 0;
}