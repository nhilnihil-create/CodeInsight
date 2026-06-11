#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
using namespace std;
int main(void){
  int N;
  cin >> N;
  string s;
  cin >> s;
  
  int r = 0;
  int b = 0;
  
  for(int i=0;i<N;i++){
    if(s[i] == 'R')
      r++;
    else
      b++;
  }
  
  if(r > b)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
  return 0;
}