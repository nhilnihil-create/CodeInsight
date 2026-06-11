#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int a=0;
  for(int i=0;i<3;i++){
    if(s[i] == 'o'){
      a++;
    }
  }
  cout<<a*100+700<<'\n';
  return 0;
}
