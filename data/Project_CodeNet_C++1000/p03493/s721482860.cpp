#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  
  cin >> a;
  
  int a100 = a / 100; // 111 / 100
  int a100_left = a % 100; //  あまり11
  int a10 = a100_left / 10; // 11 / 10
  int a10_left = a100_left % 10; // あまり1
  int a1 = a10_left / 1;
    
  cout << a100 + a10 + a1 << endl;
}