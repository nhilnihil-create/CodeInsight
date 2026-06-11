#include <iostream>
#include <string>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int d;
  cin >> d;
  string s = "Christmas";
  string e = " Eve";
  rep(i, 25-d) s += e;
  cout << s << endl;
  
  return 0;
}