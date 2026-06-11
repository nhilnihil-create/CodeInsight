#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  string S;
  cin >> S;
  
  int number = atoi(S.c_str());
  
  int f_half = (int)number/100;
  int s_half = (int)number%100;
  
  
  
  if((0<f_half && f_half<13) && (0<s_half && s_half<13)){
    cout << "AMBIGUOUS" << endl;
  }else if((0<f_half && f_half<13)){
    cout << "MMYY" << endl;
  }else if((0<s_half && s_half<13)){
    cout << "YYMM" << endl;
  }else{
    cout << "NA" << endl;
  }
  
  
  return 0;
}