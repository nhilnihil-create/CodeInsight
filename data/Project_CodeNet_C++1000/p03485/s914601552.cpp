#include <iostream>
using namespace std;

int main(){

  //initialization
  int a, b;
  int mean;
  int surplus;

  //input
  cin >> a >> b;
  
  //solver
  mean = (a + b) * 5;
  surplus = mean % 10;
  if(surplus >= 5) mean += 10;
  
  mean = (mean -surplus) / 10;
  cout << mean << "\n";
}
