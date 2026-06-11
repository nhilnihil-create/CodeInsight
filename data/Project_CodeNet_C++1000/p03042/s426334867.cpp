#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int count = 0;
  
  if (S.at(0) == '0' && S.at(1) != '0'){
    count += 10;
  }
  else if (S.at(0) == '1' && (S.at(1) == '0' || S.at(1) == '1' || S.at(1) == '2')){
    count += 10;
  }
           
  if (S.at(2) == '0' && S.at(3) != '0'){
    count += 20;
  }
  else if (S.at(2) == '1' && (S.at(3) == '0' || S.at(3) == '1' || S.at(3) == '2')){
    count += 20;
  }
           
  if (count == 30){
    cout << "AMBIGUOUS" << endl;
  }
  else if (count == 20){
    cout << "YYMM" << endl;
  }
  else if (count == 10){
    cout << "MMYY" << endl;
  }
  else {
    cout << "NA" << endl;
  }
}
  
 