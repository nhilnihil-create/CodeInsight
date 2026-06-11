#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  string S;
  cin >> S;
  if(S.size() == 3){
    reverse(S.begin(), S.end());
  }
  cout << S;
  return 0;
}