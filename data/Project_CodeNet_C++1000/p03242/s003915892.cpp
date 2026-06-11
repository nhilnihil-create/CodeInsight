#include <iostream>
using namespace std;
int main(){
  string S;
  cin >> S;
  for(auto& i:S){
    if(i == '1') cout << "9";
    else cout << "1";
  }
  cout << endl;
}