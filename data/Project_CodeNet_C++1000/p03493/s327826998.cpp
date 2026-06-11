#include <iostream>
#include <algorithm>
using namespace std;
int main(){
string s;
cin >> s;
if (s == "000") cout << 0 << endl;
if (s == "100") cout << 1 << endl;
if (s == "010") cout << 1 << endl;
if (s == "001") cout << 1 << endl;
if (s == "110") cout << 2 << endl;
if (s == "101") cout << 2 << endl;
if (s == "011") cout << 2 << endl;
if (s == "111") cout << 3 << endl;
  
  return 0;
}