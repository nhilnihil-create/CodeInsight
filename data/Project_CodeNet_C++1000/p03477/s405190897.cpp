#include <bits/stdc++.h>
using namespace std;

int main() {
  int weightA, weightB, weightC, weightD;
  cin >> weightA >> weightB >> weightC >> weightD;
  int weightL = weightA + weightB;
  int weightR = weightC + weightD;

  if(weightL> weightR){
    cout <<"Left"<<endl;
  }
  else if(weightL< weightR){
    cout <<"Right"<<endl;
  }else{
    cout <<"Balanced"<<endl;
  }

}
