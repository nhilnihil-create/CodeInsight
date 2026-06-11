#include<bits/stdc++.h>
using namespace std;

int main(){
  string S ;
  cin >> S ;
  string A = S.substr(0,2), B = S.substr(2);
  if(A >= "01" && A <= "12" && (B == "00" || B >= "13")) cout << "MMYY" << endl;
  else if(B >= "01" && B <= "12" && (A == "00" || A >= "13")) cout << "YYMM" << endl;
  else if(A >= "01" && A <= "12" && B >= "01" && B <= "12") cout << "AMBIGUOUS" << endl;
  else cout << "NA" << endl;
}
