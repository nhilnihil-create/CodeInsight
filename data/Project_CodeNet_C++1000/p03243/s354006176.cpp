#include<iostream>
using namespace std;
int main(){
  string N;
  cin>>N;
  for(int i=111; i<=999; i+=111){
    string s=to_string(i);
    if(N<=s){
      cout<<s<<endl;
      break;
    }
  }
  return 0;
}