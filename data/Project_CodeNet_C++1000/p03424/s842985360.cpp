#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N;
  cin >> N;
string iro ;
  iro = "mu";

  for( int i=0; i<N; i++){
    cin >> iro ;
    if( iro == "Y"){
      cout << "Four" << endl;
      break;}
    if( i == N-1 && iro != "Y"){
      cout << "Three"<< endl; }
   }
}