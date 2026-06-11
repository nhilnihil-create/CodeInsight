#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B =0, C =0;
  
  vector<int> OOT(200);
  cin >> A;
  
  for(int YUNI =0;YUNI < A;YUNI++){
    cin >> OOT.at(YUNI);
  }
  
  for(int YUNI =0;YUNI < A;YUNI++){
    if(C == 0){
      B += *max_element(OOT.begin(), OOT.end());
    }
    else{
      B -= *max_element(OOT.begin(), OOT.end());
    }
    
    vector<int>::iterator E = max_element(OOT.begin(), OOT.end());
    size_t F = distance(OOT.begin(), E);
    OOT.at(F) = 0;
    
    if(C == 0){
      C = 1;
    }
    else{
      C = 0;
    }
  }
  
  cout << B << endl;
}