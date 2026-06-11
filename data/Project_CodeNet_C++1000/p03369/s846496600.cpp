#include <iostream>
#include <string>
using namespace std;

int main(){
  string S;
  cin >> S;
  int sum = 700;
  for(auto itr = S.begin();itr!=S.end();itr++){
    if (*itr=='o') sum+=100;
  }
  cout << sum << endl;
}