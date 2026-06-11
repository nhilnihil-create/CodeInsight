#include<iostream>
#include<string>

using namespace std;

int main() {
  string S;
  int base = 700;
  int topping = 100;
  int count = 0;
  
  cin >> S;
  
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == 'o') ++count;
  }
  
  cout << base + topping * count << endl;
}