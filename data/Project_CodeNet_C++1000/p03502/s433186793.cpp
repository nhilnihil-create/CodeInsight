#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

  int n, a = 0, b = 0;
  string buffier;
  cin >> buffier;
  for(int i = 0;i < buffier.size();i++){
    a = a * 10 + buffier[i] - '0';
    b += buffier[i] - '0';
  }
  if(a % b == 0){
    cout << "Yes";
  }else{
    cout << "No";
  }
}
