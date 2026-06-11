#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
 int a , b , x;
 cin >> a >> b >> x;
 if(a <= x && (a + b) >= x)cout << "YES" << endl;
 else cout << "NO" << endl;
 }