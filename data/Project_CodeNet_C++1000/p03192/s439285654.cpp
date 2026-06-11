#include <iostream>
using namespace std;

int main(){
  string N;
  cin >> N;
  
  int count = 0;
  for(char c : N){
    if(c == '2') count++;
  }
  cout << count;
  return 0;
}