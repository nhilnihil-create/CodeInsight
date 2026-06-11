#include <bits/stdc++.h>
using namespace std;

int main(){
  int num, a, b, tmp;
  cin >> num;
  tmp = num / 1000;
  a = num / 10;
  b = num - (tmp * 1000);
  if (!(a % 111) || !(b % 111)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
 }