#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N; 
  string Sl;
  
  for(int i = 0; i < N; i++){
    cin >> Sl;
    if(Sl == "Y"){
      cout << "Four" << endl;
      break;
    }
    if(Sl != "Y" && i + 1 == N ){
      cout << "Three" << endl;
   }
  }
  cout << endl;
}