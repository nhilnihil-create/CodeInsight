#include <iostream>
using namespace std;

int main(){
  int S;
  cin >> S;
  
  int s1 = S / 100, s2 = S % 100;
  if(0 < s1 && s1 < 13 && 0 < s2 && s2 < 13){
    cout << "AMBIGUOUS" << endl;
    return 0;
  }else if(0 < s1 && s1 < 13){
    cout << "MMYY" << endl;
    return 0;
  }else if(0 < s2 && s2 < 13){
    cout << "YYMM" << endl;
    return 0;
  }
  cout << "NA" << endl;
  
  return 0;
}