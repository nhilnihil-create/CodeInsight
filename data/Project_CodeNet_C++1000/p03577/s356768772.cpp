#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  for(int i = 0; s.size() - 8 > i; i++){
    cout << s[i];
  }
  cout << endl;
}