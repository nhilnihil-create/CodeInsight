#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin>>s;
  int a=0;
  for(int i=0;i<4;i++){
    char x=s.at(i);
    if(x=='+'){
      a++;
    }
    else{
      a--;
    }
  }
  cout<<a<<endl;
}