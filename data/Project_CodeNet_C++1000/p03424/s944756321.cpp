#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  string A = "Three";
  
  for(int i=0; i<N; i++){

  string  x;
    
  cin >> x;

if (x == "Y"){
 A ="Four";
 break;
 }

  }
  cout << A << endl;
 return 0;

}