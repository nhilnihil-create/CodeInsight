#include <bits/stdc++.h>
using namespace std;

int main() {

int N ; cin >> N ;
int P ; P = 0;  
  for (int i ; i < N ; i++ ){
    string A ; cin >> A ;
    if (A == "Y"){
      cout << "Four" << endl;
      P = 1 ;
      break ;
    }
  }
 if (P != 1){
   cout << "Three" << endl;
 }
}