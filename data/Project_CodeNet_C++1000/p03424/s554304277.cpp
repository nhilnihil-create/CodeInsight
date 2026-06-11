#include <bits/stdc++.h>
using namespace std;
int main() {
  int f=0;
  int N;
  string C;
  cin >> N ;
  for(int i=0; i < N ; i++){
  cin >> C ;
    
    if (C == "Y"){
    cout << "Four" <<endl;
      f=1;
      break;
   
    }
  }
  if (f==0)
  {cout << "Three" <<endl;
  }
}