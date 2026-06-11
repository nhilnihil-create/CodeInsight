#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  string s , t;
  cin >> s >> t;
  if(s[0] == t[2] && s[1] == t[1] && s[2] == t[0])cout << "YES" << endl;
  else cout << "NO" << endl;
  
}
