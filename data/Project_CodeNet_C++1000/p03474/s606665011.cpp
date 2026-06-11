#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  string S;
  cin >> A >> B >> S;
  bool a=false;
  for(int  i=0;i<A+B+1;i++){
    if(i==A && S.at(i)!='-'){
      a=true;
    }
    else if(i!=A && S.at(i)=='-'){
      a=true;
    }
  }
  if(!a){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}