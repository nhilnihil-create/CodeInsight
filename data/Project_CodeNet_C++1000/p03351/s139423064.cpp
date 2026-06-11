#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  bool A = false;
  if(abs(a-c)<=d){
    A=true;
  }
  else if(abs(b-c)<=d && abs(a-b)<=d){
    A=true;
  }
  if(A){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
