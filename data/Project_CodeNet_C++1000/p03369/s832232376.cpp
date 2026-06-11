#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<char> s(3);
  for(int i=0;i<3;i++){
    cin>>s[i];
  }
  int x=700;
  for(int i=0;i<3;i++){
    if(s[i]=='o'){
      x+=100;
    }
  }
  cout<<x;
}