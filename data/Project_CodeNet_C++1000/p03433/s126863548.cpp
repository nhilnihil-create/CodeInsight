#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  cin >> A >> B;
  int C=A%500;
  
  if (C==0){
    cout<<"Yes"<<endl;
  }
  else if (C!=0){
    if (B>=C){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
  }