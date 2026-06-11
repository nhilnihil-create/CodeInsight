#include<iostream>
using namespace std;
int main(){
  int s;
  cin >> s;
  if(0<s%100 && s%100<13){
    if(0<s/100 && s/100<13){
      cout << "AMBIGUOUS" << endl;
    }
    else{
      cout << "YYMM" << endl;
    }
  }
  else if(0<s/100 && s/100<13){
    cout << "MMYY" << endl;
  }
  else{
    cout << "NA" << endl;
  }
  return 0;
}