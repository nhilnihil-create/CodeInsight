#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  int a , b , c , d;
  cin >> a >> b >> c >> d;
  int k = b - a;
  int l = c - b;
  int t = c - a;
  if(k < 0)k = a - b;
  if(l < 0)l = b - c;
  if(t < 0)t = a - c;
  if(t <= d)cout << "Yes" << endl;
  else if(k <= d && l <= d)cout << "Yes" << endl;
  else cout << "No" << endl;
}
