#include<iostream>
using namespace std;
int main(){
  string s;
  for(int i = 0; i < 9; i++){
    char a; cin >> a;
    s.push_back(a);
  }
  cout << s.at(0) << s.at(4) << s.at(8);
}
