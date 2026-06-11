#include <bits/stdc++.h>
using namespace std;

int main() {
  int s;
  cin >> s;
  int mae = s/100;
  int ushiro = s%100;
  bool mb = false;
  bool ub = false;
  
  if (1 <= mae && mae <= 12){
    mb = true;
  }
  if (1 <= ushiro && ushiro <= 12){
    ub = true;
  }
  
  if (mb == true && ub == true){
    cout << "AMBIGUOUS" << endl;
  }
  if (mb == true && ub == false){
    cout << "MMYY" << endl;
  }
  if (mb == false && ub == true){
    cout << "YYMM" << endl;
  }
  if (mb == false && ub == false){
    cout << "NA" << endl;
  }

}
