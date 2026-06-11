#include <iostream>
using namespace std;

int main() {
  char str[128];
  int a,b,c;
  cin >> a >> b;
  if(a*b%2 == 0){
    cout << "Even" << endl;
  }else{
    cout << "Odd" << endl;
  }
}