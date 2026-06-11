#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  
  cin >> N;
  
  int i=0;
  
  while (i<N){
    string Si;
    cin >> Si;
    
    if ( Si == "Y" ){
      break;
    }
    i++;
  }
  
  if ( i<N )
    cout << "Four" << endl;
  else
    cout << "Three" << endl;
}