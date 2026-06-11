#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int a=0;
  int b=1;
  cin >>N;
  for (int i=0; i<8; i++){
    
    a+= N%(b*10)/b;
      b*=10;
    }
  if (N%a==0){
    cout << "Yes" << endl;
  }
  else
    cout << "No" << endl;
}
   