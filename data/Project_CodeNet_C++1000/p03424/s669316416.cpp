#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>> N;
  int a=0;
  for(int i=0 ; i<N ; i++){
    string s;
    cin>> s ;
    if(s=="Y"){
      a++;
    }
  }
  if(a==0){
    cout<< "Three" << endl;
  }
  else{
    cout<< "Four" << endl;
  }
}