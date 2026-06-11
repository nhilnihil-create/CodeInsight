#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  string S;
  cin >> N >> K >> S;
  
  char small;
  switch(S.at(K-1)){
    case 'A':
      small = 'a';
      break;
    case 'B':
      small = 'b';
      break;
    case 'C':
      small = 'c';
      break;
  }
  S.at(K-1) = small;
  cout << S << endl;
}