#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int a = N/1000, d = N%10, b = (N%1000-N%100)/100, c = (N%100-N%10)/10;
  
  if (a == b && a == c && a == d)  {
    cout << "Yes" << endl;  
  }
  
  else {
    if (   a != b && b == c && b == d
        || d != a && a == b && a == c ){
      cout << "Yes" << endl;
    }
    
    else {
      cout << "No" << endl;
    }
  }


}