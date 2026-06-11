#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  
  cin >> A;
  
  map<string, int> OOT;
  vector<string> JNY(200);
  vector<string> TKB(200);
  vector<int> PPP(200);
  
  for(int YUNI=0;YUNI < A; YUNI++){
    cin >> JNY.at(YUNI);
  }
  
  for(int YUNI=0;YUNI < A; YUNI++){
    OOT[JNY.at(YUNI)]++;
  }
  
  cin >> B;
  
  for(int YUNI=0;YUNI < B; YUNI++){
    cin >> TKB.at(YUNI);
  }
  
  for(int YUNI=0;YUNI < B; YUNI++){
    OOT[TKB.at(YUNI)]--;
  }
  
  vector<int> TOKYO(100);
  
  for(int YUNI=0;YUNI < A; YUNI++){
    TOKYO.at(YUNI) = OOT[JNY.at(YUNI)];
  }
  
  int D = *max_element(TOKYO.begin(), TOKYO.end());
  
  //if(D <= 0){
  //  D = 0;
  //}
  
  cout << D << endl;
}