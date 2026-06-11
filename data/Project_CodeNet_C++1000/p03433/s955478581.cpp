#include <bits/stdc++.h>
using namespace std;

int main() {
  int pay_money ;
  int number ;
  cin >> pay_money >> number ;
  int nokori = pay_money % 500 ;
  int donnna = number - nokori ;
  
  if (donnna >= 0){
    cout << "Yes" << endl ;
  }
  else {
    cout << "No" << endl ;
  }
}