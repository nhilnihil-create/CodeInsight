#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a=n/100;
  int b=n%100;
  int mmyy=1,yymm=1;
  
  mmyy*=(a<=12&&a!=0);
  yymm*=(b<=12&&b!=0);
  
  if(mmyy*yymm) cout << "AMBIGUOUS" << endl;
  else if(mmyy==1&&yymm==0) cout << "MMYY" << endl;
  else if(yymm==1&&mmyy==0) cout << "YYMM" << endl;
  else cout << "NA" << endl;
}