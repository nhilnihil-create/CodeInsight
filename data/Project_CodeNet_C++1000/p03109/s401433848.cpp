#include<iostream>
using namespace std;

int main(){
  string S;
  cin >> S;
  cout << (S > "2019/04/30" ? "TBD" : "Heisei") << endl;
  return 0;
}