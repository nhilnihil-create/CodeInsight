#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B =0, C =0, D =0;
  
  cin >> A;
  vector<int> OOT(100);
  for(int YUNI =0; YUNI < A;YUNI++){
    cin >> OOT.at(YUNI);
  }
  
  for(int YUNI =0; YUNI < A;YUNI++){
    B = *max_element(OOT.begin(), OOT.end());
    if(B != C){
      D ++;
    }
    C = B;
    vector<int>::iterator E = max_element(OOT.begin(), OOT.end());
    size_t F = distance(OOT.begin(), E);
    OOT.at(F) = 0;
  }
  cout << D << endl;
}