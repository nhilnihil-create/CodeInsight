#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int c = 0;
  cin>>s;
  for(int i=0;i<4;i++){
    if(s[i] == '+'){
      c++;
    }
    else{
      c--;
    }
  }
  cout<<c<<'\n';
  return 0;
}
  
