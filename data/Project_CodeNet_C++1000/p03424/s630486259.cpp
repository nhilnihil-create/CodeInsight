#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, c;
  string S;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> S;
    if(S != "Y")continue;
    else{
      cout << "Four" << endl;
      break;
    }
  }
  if(S != "Y")cout << "Three" << endl;
}