#include <bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin >> a;
  int l = a/100;
  int r = a%100;
  if(1 <= l && l <=12){
      if(1 <= r && r <= 12){
          cout << "AMBIGUOUS\n" << endl;
      }else{
          cout << "MMYY\n" << endl;
      }
  }else{
      if(1 <= r && r <= 12){
          cout << "YYMM\n" << endl;
      }else{
          cout << "NA\n" << endl;
      }
  }
  return 0;
}
