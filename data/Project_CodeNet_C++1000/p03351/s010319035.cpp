#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin >>a>>b>>c>>d;
  bool hantei=false;
  if(abs(a-b)<=d){
    if(abs(b-c)<=d){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  if(abs(a-c)<=d){
    cout<<"Yes"<<endl;
    return 0;
  }
  cout<<"No"<<endl;
  return 0;
}