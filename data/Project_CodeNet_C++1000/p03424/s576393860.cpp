#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, P, B;
  P = 1;
  string S;
  cin >> N;
  while( N-P>0){
    cin >> S;
    if(S=="Y"){
      cout << "Four" << endl;
      break;
    }
    P++;
  }
  if( N-P==0){
    if( S=="Y"){
      cout << "Four" << endl;
    }
    else if( S!="Y"){
      cout << "Three" << endl;
    }
  }

}
