#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  int a , b , c;
  cin >> a >> b >> c;
  if(a + b >= c)cout << "Yes" << endl;
  else cout << "No" << endl;
}
