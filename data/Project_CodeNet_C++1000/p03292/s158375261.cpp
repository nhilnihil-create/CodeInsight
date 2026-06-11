#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
 int a , b , c;
  cin >> a >> b >> c;
  cout << max({a , b , c}) - min({a , b , c}) << endl;
}
