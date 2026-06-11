#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int S;
  cin >> S;
  int flag1=0;
  int flag2=0;
  if(1<=S%100 && S%100<=12){
    flag1=1;
  }
  if(1<=S/100 && S/100<=12){
    flag2=1;
  }
  if(flag1==1 && flag2==1){
    cout << "AMBIGUOUS" << endl;
    return 0;
  }
  else if(flag1==1 && flag2==0){
    cout << "YYMM" << endl;
    return 0;
  }
  else if(flag1==0 && flag2==1){
    cout << "MMYY" << endl;
    return 0;
  }
  else{
    cout << "NA" << endl;
    return 0;
  }
}