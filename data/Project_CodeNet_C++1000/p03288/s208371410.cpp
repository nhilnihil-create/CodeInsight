#include <iostream>
using namespace std;

int main(){
  
  int N;
  cin >> N;
  if(N < 1200)cout << "ABC";
  else if(N >= 1200 && N < 2800)cout << "ARC";
  else cout << "AGC";
}