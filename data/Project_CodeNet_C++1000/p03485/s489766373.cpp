#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,result;
  
  cin >> a >> b;
  double DoubleRes = ( a + b ) / 2.0;
  int intRes = ( a + b ) / 2;
  
  if(DoubleRes-intRes>=0.5){
    result = intRes+1;
  }else{
    result = intRes;
  }
  
  cout << result << endl;
}