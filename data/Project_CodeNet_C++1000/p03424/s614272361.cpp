#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  bool flag=false;
  char A[100];
  cin >> N ;
  
  for(int i=0;i<N;i++){
    cin >> A[i] ;
    if(A[i]=='Y'){
      flag=true;
    }
  }
  if(flag){
    cout << "Four" <<endl;
  }else{
    cout << "Three" <<endl;
  }
}
