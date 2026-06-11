#include <bits/stdc++.h>
using namespace std;
//B - Addition and Multiplication
int main() {
  int n, k;
  cin >> n >> k;
  int number = 1;
  for(int i = 0;i < n; i++){
    if(number*2 < number + k)
      number = number*2;
    else
      number += k;
  }
  cout << number << endl;
}
