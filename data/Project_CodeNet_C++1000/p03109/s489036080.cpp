#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int A,B,C;
  char x,y;
  cin>>A>>x>>B>>y>>C;
  
  if(A>2019){
    cout<<"TBD"<<endl;
  }
  else if(A==2019){
    if(B>4){
      cout<<"TBD"<<endl;
    }
    else if(B<=4){
      cout<<"Heisei"<<endl;
    }
  }
  else{
    cout<<"Heisei"<<endl;
  }
}