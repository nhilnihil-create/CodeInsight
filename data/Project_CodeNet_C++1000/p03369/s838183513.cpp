#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
  	int price;
    cin >> s;
    int counter = 0;
    if (s[0] == 'o') ++counter;
    if (s[1] == 'o') ++counter;
    if (s[2] == 'o') ++counter;
  
  	price = 700 + 100 * counter;
    
  cout << price << endl;
  
  
}