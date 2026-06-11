#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  
  bool yes = true;
  if(abs(a - c) > d){
    if(abs(a-b) > d || abs(b-c) > d){
      yes = false;
    }
  }
  
  if(yes){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  return 0;
}
