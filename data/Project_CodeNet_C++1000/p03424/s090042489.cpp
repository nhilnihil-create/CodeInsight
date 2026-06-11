#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int i = 0;
  while (i < N){
    string C;
    cin >> C;
    
    if(C == "W"){
      i++;
    }
    if(C == "P"){
      i++;
    }
    if(C == "G"){
      i++;
    }
    if(C == "Y"){
      cout << "Four" << endl;
      break;
    }
    
    if(i == N-1){
      cout << "Three" << endl;
    }
  }
}