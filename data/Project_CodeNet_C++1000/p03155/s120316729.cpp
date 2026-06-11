#include<iostream>
using namespace std;
int main(void){
  int a,b,c;
  string s;
  cin >> a >> b >> c;
  cout << (a - (b - 1)) * (a - (c - 1));
}