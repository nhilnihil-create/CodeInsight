#include<iostream>
using namespace std;

int main() {
  int i,sum=0;
  char ch;
  
  for(i=0;i<3;i++) {
    cin >> ch;
    if(ch == '1') sum++;
  }
  
  cout << sum << endl;

  return 0;
}