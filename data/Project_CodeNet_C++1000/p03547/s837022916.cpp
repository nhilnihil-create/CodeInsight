#include <bits/stdc++.h>
using namespace std;

int main() {
  char a,b;
  cin>>a>>b;
  if(a-b>0){
    cout<<">"<<endl;
  }else if(b-a>0){
    cout<<"<"<<endl;
  }else if(a==b){
    cout<<"="<<endl;
  }
  return 0;
}