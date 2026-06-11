#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,a1,a2,a3,a4;
  cin >> N;
  
  a1=N%10;
  a2=(N-a1)/10%10;
  a3=(N-a1-a2*10)/100%10;
  a4=(N-a1-a2*10-a3*100)/1000%10;

  if ((a1==a2 && a1==a3) || (a2==a3 && a2==a4)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }  
}