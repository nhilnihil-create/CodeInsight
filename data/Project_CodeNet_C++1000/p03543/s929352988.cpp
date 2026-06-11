#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  
  string Nstr=to_string(N);
  char current_char='a';
  int count=0;
  string good="No";
  for(char c:Nstr){
    if(current_char==c){
      count++;
      if(count>=3)
        good="Yes";
    }else{
      current_char=c;
      count=1;
    }
  }
  cout<<good<<endl;
}
  