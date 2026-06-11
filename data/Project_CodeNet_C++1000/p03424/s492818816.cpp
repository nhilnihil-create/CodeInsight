#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  int P = 0;
  int G = 0;
  int W = 0;
  int Y = 0;
  
  for (int i = 0; i < N; i++){
    
    string S;
    cin >> S;
    
    if (S == "P"){
      P = P  + 1;
    }
    else if (S == "G"){
      G = G + 1;
    }
    else if (S == "W"){
      W = W + 1;
    }
    else if (S == "Y"){
      Y = Y + 1;
    }
    
  }
  
  if (P > 0 && W >0){
    if (Y > 0 && G > 0){
		cout << "Four" << endl;
    }
    else{
	cout << "Three" << endl;
    }
  }
  else{
	cout << "Three" << endl;
  }
  
  

 }