#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string N;cin>>N;
  bool F=false;
  for(int X=N.size()-1;X>0;X--){
    if(N[X]!='9'){
      F=true;
    }
  }
  if(!F){
    cout<<((int)N[0])-48+9*(N.size()-1)<<endl;
  }
  else{
    cout<<(int)N[0]-49+9*(N.size()-1)<<endl;
  }
}