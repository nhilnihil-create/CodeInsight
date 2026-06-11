#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  char a , b;
  cin >> a >> b;
  if(a > b)cout << '>' << endl;
  else if(a == b)cout << '=' << endl;
  else cout << '<' << endl;
}
