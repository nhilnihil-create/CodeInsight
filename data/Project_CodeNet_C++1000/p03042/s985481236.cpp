#include <iostream>
#include <string>
using namespace std;

int main(){
  string S;
  cin >> S;
  
  string s1 = S.substr(0, 2), s2 = S.substr(2, 2);
  if("00" < s1 && s1 < "13" && "00" < s2 && s2 < "13"){
    cout << "AMBIGUOUS" << endl;
    return 0;
  }else if("00" < s1 && s1 < "13"){
    cout << "MMYY" << endl;
    return 0;
  }else if("00" < s2 && s2 < "13"){
    cout << "YYMM" << endl;
    return 0;
  }
  cout << "NA" << endl;
  
  return 0;
}