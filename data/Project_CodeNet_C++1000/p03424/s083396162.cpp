#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, p = 0, w = 0, g = 0, y = 0;
  string a;
  cin >> N;

  for(int i = 0; i < N; i++){
    cin >> a;
    if(a == "P"){p++;}
    else if(a == "W"){w++;}
    else if(a == "G"){g++;}
    else if(a == "Y"){y++;}
  }
 
  if(p>=1 && w>=1 && g>=1 && y>=1){cout << "Four" << endl;}
  else{cout << "Three" << endl;}
}
