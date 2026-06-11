#include<iostream>
#include<string>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(a<c){
    if(c<b){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else{
    if(b<c){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  return 0;
}