#include <iostream>
using namespace std;

int main(){
  int s;
  cin >> s;
  int a, b, c;
  cout << (s / 100) + (s % 100 / 10) + (s % 100 % 10 / 1) << endl;
}